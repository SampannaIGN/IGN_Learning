#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
//#include "clahe_custom.h"


#include <vector>       // std::vector
using namespace cv;
using namespace std;

char img_path[] = "/home/edgeai/code/b7932272-8e55-74c7-3eb5-acfee9cfed10.png";

#include <stdlib.h>			 /* To get prototypes of malloc() and free() */
#define BYTE_IMAGE 1
#ifdef BYTE_IMAGE
typedef unsigned char kz_pixel_t;	 /* for 8 bit-per-pixel images */
#define uiNR_OF_GREY (256)
#else
typedef unsigned short kz_pixel_t;	 /* for 12 bit-per-pixel images (default) */
# define uiNR_OF_GREY (4096)
#endif

const unsigned int uiMAX_REG_X = 16;	  /* max. # contextual regions in x-direction */
const unsigned int uiMAX_REG_Y = 16;	  /* max. # contextual regions in y-direction */


/************************ Prototype of CLAHE function************************/
int CLAHE_CUSTOM (kz_pixel_t* pImage, unsigned int uiXRes, unsigned int uiYRes,
	 kz_pixel_t Min, kz_pixel_t Max, unsigned int uiNrX, unsigned int uiNrY,
	      unsigned int uiNrBins, float fCliplimit);

/************************ Local prototypes ************************/
void ClipHistogram (unsigned long* pulHistogram, unsigned int
		     uiNrGreylevels, unsigned long ulClipLimit);
             
void MakeHistogram (kz_pixel_t* pImage, unsigned int uiXRes,
		unsigned int uiSizeX, unsigned int uiSizeY,
		unsigned long* pulHistogram,
		unsigned int uiNrGreylevels, kz_pixel_t* pLookupTable);
        
void MapHistogram (unsigned long* pulHistogram, kz_pixel_t Min, kz_pixel_t Max,
	       unsigned int uiNrGreylevels, unsigned long ulNrOfPixels);
           
void MakeLut (kz_pixel_t * pLUT, kz_pixel_t Min, kz_pixel_t Max, unsigned int uiNrBins);

void Interpolate (kz_pixel_t * pImage, int uiXRes, unsigned long * pulMapLU,
     unsigned long * pulMapRU, unsigned long * pulMapLB,  unsigned long * pulMapRB,
     unsigned int uiXSize, unsigned int uiYSize, kz_pixel_t * pLUT);


/************************** main function CLAHE ******************/
int CLAHE_CUSTOM (kz_pixel_t* pImage, unsigned int uiXRes, unsigned int uiYRes,
	 kz_pixel_t Min, kz_pixel_t Max, unsigned int uiNrX, unsigned int uiNrY,
	      unsigned int uiNrBins, float fCliplimit)
/*   pImage - Pointer to the input/output image
 *   uiXRes - Image resolution in the X direction
 *   uiYRes - Image resolution in the Y direction
 *   Min - Minimum greyvalue of input image (also becomes minimum of output image)
 *   Max - Maximum greyvalue of input image (also becomes maximum of output image)
 *   uiNrX - Number of contextial regions in the X direction (min 2, max uiMAX_REG_X)
 *   uiNrY - Number of contextial regions in the Y direction (min 2, max uiMAX_REG_Y)
 *   uiNrBins - Number of greybins for histogram ("dynamic range")
 *   float fCliplimit - Normalized cliplimit (higher values give more contrast)
 * The number of "effective" greylevels in the output image is set by uiNrBins; selecting
 * a small value (eg. 128) speeds up processing and still produce an output image of
 * good quality. The output image will have the same minimum and maximum value as the input
 * image. A clip limit smaller than 1 results in standard (non-contrast limited) AHE.
 */
{
    unsigned int uiX, uiY;		  /* counters */
    unsigned int uiXSize, uiYSize, uiSubX, uiSubY; /* size of context. reg. and subimages */
    unsigned int uiXL, uiXR, uiYU, uiYB;  /* auxiliary variables interpolation routine */
    unsigned long ulClipLimit, ulNrPixels;/* clip limit and region pixel count */
    kz_pixel_t* pImPointer;		   /* pointer to image */
    kz_pixel_t aLUT[uiNR_OF_GREY];	    /* lookup table used for scaling of input image */
    unsigned long* pulHist, *pulMapArray; /* pointer to histogram and mappings*/
    unsigned long* pulLU, *pulLB, *pulRU, *pulRB; /* auxiliary pointers interpolation */

    if (uiNrX > uiMAX_REG_X) return -1;	   /* # of regions x-direction too large */
    if (uiNrY > uiMAX_REG_Y) return -2;	   /* # of regions y-direction too large */
    if (uiXRes % uiNrX) return -3;	  /* x-resolution no multiple of uiNrX */
    if (uiYRes % uiNrY) return -4;	  /* y-resolution no multiple of uiNrY */
    if (Max >= uiNR_OF_GREY) return -5;	   /* maximum too large */
    if (Min >= Max) return -6;		  /* minimum equal or larger than maximum */
    if (uiNrX < 2 || uiNrY < 2) return -7;/* at least 4 contextual regions required */
    if (fCliplimit == 1.0) return 0;	  /* is OK, immediately returns original image. */
    if (uiNrBins == 0) uiNrBins = 128;	  /* default value when not specified */

    pulMapArray=(unsigned long *)malloc(sizeof(unsigned long)*uiNrX*uiNrY*uiNrBins);
    if (pulMapArray == 0) return -8;	  /* Not enough memory! (try reducing uiNrBins) */

    uiXSize = uiXRes/uiNrX; uiYSize = uiYRes/uiNrY;  /* Actual size of contextual regions */
    printf("uiXRes %d uiNrX %d  ,uiXSize %d, uiYRes %d uiNrY %d uiYSize %d \n ", uiXRes,  uiNrX  ,uiXSize, uiYRes, uiNrY, uiYSize);
    ulNrPixels = (unsigned long)uiXSize * (unsigned long)uiYSize;
    printf("ulNrPixels the grid pixels %d \n",ulNrPixels);
    if(fCliplimit > 0.0)
    {		  /* Calculate actual cliplimit	 */
       ulClipLimit = (unsigned long) (fCliplimit * (uiXSize * uiYSize) / uiNrBins);
       ulClipLimit = (ulClipLimit < 1UL) ? 1UL : ulClipLimit;
    }
    else ulClipLimit = 1UL<<14;		  /* Large value, do not clip (AHE) */
    printf("ulClipLimit, %d \n",ulClipLimit);

    MakeLut(aLUT, Min, Max, uiNrBins);	  /* Make lookup table for mapping of greyvalues */
    /* Calculate greylevel mappings for each contextual region */
    printf("uiNrBins %d \n",uiNrBins);
    for (uiY = 0, pImPointer = pImage; uiY < uiNrY; uiY++) 
    {
	    for (uiX = 0; uiX < uiNrX; uiX++, pImPointer += uiXSize) 
        {
            //printf("Total no of bins uiNrBins %d current y uiY %d current X uiX %d, uiNrX bin width %d \n ",uiNrBins , uiY,uiX, uiNrX);
	        pulHist = &pulMapArray[uiNrBins * (uiY * uiNrX + uiX)];
            //printf("%d \n",(uiNrBins * (uiY * uiNrX + uiX)));
            //printf("pulHist %lu \n",pulHist);
	        MakeHistogram(pImPointer,uiXRes,uiXSize,uiYSize,pulHist,uiNrBins,aLUT);
            
	        ClipHistogram(pulHist, uiNrBins, ulClipLimit);
	        MapHistogram(pulHist, Min, Max, uiNrBins, ulNrPixels);
	    }
	    pImPointer += (uiYSize - 1) * uiXRes;		  /* skip lines, set pointer */
    }
    
    /* Interpolate greylevel mappings to get CLAHE image */
    for (pImPointer = pImage, uiY = 0; uiY <= uiNrY; uiY++)
    {
	    if (uiY == 0) 
        {	
            /* special case: top row */			 
	        uiSubY = uiYSize >> 1;  uiYU = 0; uiYB = 0;
            printf("Special case top row after %d \n", uiSubY);
	    }
	    else
        {
	        if (uiY == uiNrY) 
            {				  /* special case: bottom row */
                uiSubY = (uiYSize+1) >> 1;	uiYU = uiNrY-1;	 uiYB = uiYU;
	        }
	        else 
            {					  /* default values */
		        uiSubY = uiYSize; uiYU = uiY - 1; uiYB = uiYU + 1;
	        }
	    }
	    for (uiX = 0; uiX <= uiNrX; uiX++)
        {
	        if (uiX == 0) 
            {				  /* special case: left column */
		        uiSubX = uiXSize >> 1; uiXL = 0; uiXR = 0;
	        }
	        else
            {
		        if (uiX == uiNrX) 
                {			  /* special case: right column */
                    uiSubX = (uiXSize+1) >> 1;  uiXL = uiNrX - 1; uiXR = uiXL;
		        }
		        else 
                {					  /* default values */
		            uiSubX = uiXSize; uiXL = uiX - 1; uiXR = uiXL + 1;
		        }
	        }
            printf("uiX %d , uiY %d , uiYU %d , uiYB %d , uiXL %d , uiXR %d , uiNrX %d \n",uiX  , uiY  , uiYU , uiYB  , uiXL  , uiXR , uiNrX);
	        pulLU = &pulMapArray[uiNrBins * (uiYU * uiNrX + uiXL)];
	        pulRU = &pulMapArray[uiNrBins * (uiYU * uiNrX + uiXR)];
            pulLB = &pulMapArray[uiNrBins * (uiYB * uiNrX + uiXL)];
	        pulRB = &pulMapArray[uiNrBins * (uiYB * uiNrX + uiXR)];
	        Interpolate(pImPointer,uiXRes,pulLU,pulRU,pulLB,pulRB,uiSubX,uiSubY,aLUT);
	        pImPointer += uiSubX;			  /* set pointer on next matrix */
	    }
	    pImPointer += (uiSubY - 1) * uiXRes;
    }
    free(pulMapArray);					  /* free space for histograms */
    return 0;						  /* return status OK */
}
void ClipHistogram (unsigned long* pulHistogram, unsigned int
		     uiNrGreylevels, unsigned long ulClipLimit)
/* This function performs clipping of the histogram and redistribution of bins.
 * The histogram is clipped and the number of excess pixels is counted. Afterwards
 * the excess pixels are equally redistributed across the whole histogram (providing
 * the bin count is smaller than the cliplimit).
 */
{
    unsigned long* pulBinPointer, *pulEndPointer, *pulHisto;
    unsigned long ulNrExcess, ulUpper, ulBinIncr, ulStepSize, i;
    long lBinExcess;

    ulNrExcess = 0;  pulBinPointer = pulHistogram;
    for (i = 0; i < uiNrGreylevels; i++) 
    { /* calculate total number of excess pixels */
	    lBinExcess = (long) pulBinPointer[i] - (long) ulClipLimit;
        if (lBinExcess > 0) 
            ulNrExcess += lBinExcess;	  /* excess in current bin */
    };

    /* Second part: clip histogram and redistribute excess pixels in each bin */
    ulBinIncr = ulNrExcess / uiNrGreylevels;		  /* average binincrement */
    ulUpper =  ulClipLimit - ulBinIncr;	 /* Bins larger than ulUpper set to cliplimit */
    printf("ulBinIncr %d , ulNrExcess %d , ulUpper %d \n", ulBinIncr,ulNrExcess ,ulUpper );
    for (i = 0; i < uiNrGreylevels; i++)
    {
        if (pulHistogram[i] > ulClipLimit) 
            pulHistogram[i] = ulClipLimit; /* clip bin */
        else 
        {
	        if (pulHistogram[i] > ulUpper)
            {		/* high bin count */
	            ulNrExcess -= pulHistogram[i] - ulUpper;
                pulHistogram[i]=ulClipLimit;
	        }
	        else 
            {					/* low bin count */
                //printf("Excess distribution in low bins ulBinIncr %d pulHistogram[i] %d \n", ulBinIncr , pulHistogram[i]);
	            ulNrExcess -= ulBinIncr; 
                pulHistogram[i] += ulBinIncr;
	        }
       }
    }

    while (ulNrExcess) 
    {   /* Redistribute remaining excess  */
	    pulEndPointer = &pulHistogram[uiNrGreylevels];
        pulHisto = pulHistogram;

	    while (ulNrExcess && pulHisto < pulEndPointer) 
        {
	        ulStepSize = uiNrGreylevels / ulNrExcess;
	        if (ulStepSize < 1)
                ulStepSize = 1;		  /* stepsize at least 1 */
	        for (pulBinPointer=pulHisto; pulBinPointer < pulEndPointer && ulNrExcess;pulBinPointer += ulStepSize) 
            {
		        if (*pulBinPointer < ulClipLimit) 
                {
		            (*pulBinPointer)++;	 
                    ulNrExcess--;	  /* reduce excess */
		        }
	        }
	        pulHisto++;		  /* restart redistributing on other bin location */
	    }
    }
}
void MakeHistogram (kz_pixel_t* pImage, unsigned int uiXRes,
		unsigned int uiSizeX, unsigned int uiSizeY,
		unsigned long* pulHistogram,
		unsigned int uiNrGreylevels, kz_pixel_t* pLookupTable)
/* This function classifies the greylevels present in the array image into
 * a greylevel histogram. The pLookupTable specifies the relationship
 * between the greyvalue of the pixel (typically between 0 and 4095) and
 * the corresponding bin in the histogram (usually containing only 128 bins).
 */
{
    kz_pixel_t* pImagePointer;
    unsigned int i;

    for (i = 0; i < uiNrGreylevels; i++)
        pulHistogram[i] = 0L; /* clear histogram */

    for (i = 0; i < uiSizeY; i++)
    {
		pImagePointer = &pImage[uiSizeX];
		while (pImage < pImagePointer)
            //increment the pulHistogram bit that corresponds to the
            //image bit at that position. Foreg : pImage at a point has value 200
            //increment the pulHistogram bit which the value corresponding to the value
            //for that bit in lookuptable. This is a case where in the number of bins are 
            //varied. otherwise if bin is kept constant the pLookupTable may not be required at
            //all. Direct *pImage will get to the corresponding value in pulHistorgram
            pulHistogram[pLookupTable[*pImage++]]++;
            //printf("At this point pulHistogram %d pLookupTable[*pImage] %d *pImage %d \n",pulHistogram[pLookupTable[*pImage]], pLookupTable[*pImage], *pImage);
		pImagePointer += uiXRes;
		pImage = &pImagePointer[-(int)uiSizeX];	/* go to beginning of next row */
    }
}

void MapHistogram (unsigned long* pulHistogram, kz_pixel_t Min, kz_pixel_t Max,
	       unsigned int uiNrGreylevels, unsigned long ulNrOfPixels)
/* This function calculates the equalized lookup table (mapping) by
 * cumulating the input histogram. Note: lookup table is rescaled in range [Min..Max].
 */
{
    unsigned int i;  unsigned long ulSum = 0;
    const float fScale = ((float)(Max - Min)) / ulNrOfPixels;
    const unsigned long ulMin = (unsigned long) Min;

    for (i = 0; i < uiNrGreylevels; i++)
    {
        //printf("Before ulSum %d , pulHistogram[i] %d \n", ulSum , pulHistogram[i]);
		ulSum += pulHistogram[i];
        
        pulHistogram[i]=(unsigned long)(ulMin+ulSum*fScale);
        //printf("After ulSum %d , pulHistogram[i] %d \n", ulSum , pulHistogram[i]);
		if (pulHistogram[i] > Max) 
            pulHistogram[i] = Max;
    }
}

void MakeLut (kz_pixel_t * pLUT, kz_pixel_t Min, kz_pixel_t Max, unsigned int uiNrBins)
/* To speed up histogram clipping, the input image [Min,Max] is scaled down to
 * [0,uiNrBins-1]. This function calculates the LUT.
 */
{
    int i;
    const kz_pixel_t BinSize = (kz_pixel_t) (1 + (Max - Min) / uiNrBins);

    for (i = Min; i <= Max; i++) 
    {   
        pLUT[i] = (i - Min) / BinSize;
        printf("LUT % i %d \n",i , pLUT[i]);
    }
}

void Interpolate (kz_pixel_t * pImage, int uiXRes, unsigned long * pulMapLU,
     unsigned long * pulMapRU, unsigned long * pulMapLB,  unsigned long * pulMapRB,
     unsigned int uiXSize, unsigned int uiYSize, kz_pixel_t * pLUT)
/* pImage      - pointer to input/output image
 * uiXRes      - resolution of image in x-direction
 * pulMap*     - mappings of greylevels from histograms
 * uiXSize     - uiXSize of image submatrix
 * uiYSize     - uiYSize of image submatrix
 * pLUT	       - lookup table containing mapping greyvalues to bins
 * This function calculates the new greylevel assignments of pixels within a submatrix
 * of the image with size uiXSize and uiYSize. This is done by a bilinear interpolation
 * between four different mappings in order to eliminate boundary artifacts.
 * It uses a division; since division is often an expensive operation, I added code to
 * perform a logical shift instead when feasible.
 */
{
    const unsigned int uiIncr = uiXRes-uiXSize; /* Pointer increment after processing row */
    kz_pixel_t GreyValue;
    unsigned int uiNum = uiXSize*uiYSize; /* Normalization factor */

    unsigned int uiXCoef, uiYCoef, uiXInvCoef, uiYInvCoef, uiShift = 0;

    if (uiNum & (uiNum - 1)) 
    {
      /* If uiNum is not a power of two, use division */
        for (uiYCoef = 0, uiYInvCoef = uiYSize; uiYCoef < uiYSize;uiYCoef++, uiYInvCoef--,pImage+=uiIncr) 
        {
	        for (uiXCoef = 0, uiXInvCoef = uiXSize; uiXCoef < uiXSize; uiXCoef++, uiXInvCoef--) 
            {
	            GreyValue = pLUT[*pImage];		   /* get histogram bin value */
	            *pImage++ = (kz_pixel_t ) ((uiYInvCoef * (uiXInvCoef*pulMapLU[GreyValue]
				            + uiXCoef * pulMapRU[GreyValue])
				            + uiYCoef * (uiXInvCoef * pulMapLB[GreyValue]
				            + uiXCoef * pulMapRB[GreyValue])) / uiNum);
	        }
        }
    }
    else 
    {			   /* avoid the division and use a right shift instead */
	    while (uiNum >>= 1) uiShift++;		   /* Calculate 2log of uiNum */
	    for (uiYCoef = 0, uiYInvCoef = uiYSize; uiYCoef < uiYSize;uiYCoef++, uiYInvCoef--,pImage+=uiIncr) 
        {
	        for (uiXCoef = 0, uiXInvCoef = uiXSize; uiXCoef < uiXSize;uiXCoef++, uiXInvCoef--) 
            {
	            GreyValue = pLUT[*pImage];	  /* get histogram bin value */
	            *pImage++ = (kz_pixel_t)((uiYInvCoef* (uiXInvCoef * pulMapLU[GreyValue]
				        + uiXCoef * pulMapRU[GreyValue])
				        + uiYCoef * (uiXInvCoef * pulMapLB[GreyValue]
				        + uiXCoef * pulMapRB[GreyValue])) >> uiShift);
	        }
	    }
    }
}


int main()
{   

    // READ RGB color image and convert it to Lab
    printf("Read image \n");
    Mat bgr_image = imread(img_path);
    imshow("image grey", bgr_image);
        
    Mat gray_image;
    
    printf("Read image done \n");

    int img_width = bgr_image.size().width;
    int img_height = bgr_image.size().height;

    printf("Read image grep image convert w %d h %d \n", img_width , img_height);
    cvtColor(bgr_image, gray_image,cv::COLOR_BGR2GRAY);
    printf("Read image grep image convert done \n");
    
    //cout << setw(10) << (int)gray_image.at<uchar>(0,310)<<endl;
    
    // int8_t img_array[img_width][img_height];
    
    // for(int i =0;i<img_width;i++)
    // {
    //    for(int j =0;j<img_height;j++)
    //    {
    //        img_array[i][j] = (int)gray_image.at<uchar>(i,j);
    //    }
    // }
    //imshow("image grey", gray_image);

    // unsigned int* pIn= (unsigned  int *)&img_array[0][0];
    
    //int result = CLAHE_CUSTOM(gray_image.data,img_width,img_height,0,255,16,5,256,40);
    int result = CLAHE_CUSTOM(gray_image.data,img_width,img_height,0,255,16,5,256,40);
    printf("CLAHE execution done result %d  \n", result);
   

   // Merge the the color planes back into an Lab image

  // display the results  (you might also want to see lab_planes[0] before and after).
 // imshow("image original", ray_image);
  //cvtColor(bgr_image, gray_image,cv::COLOR_GRAY2BGR);
  imshow("image grey_1", gray_image);
  //imshow("image CLAHE CPP", dst);
  waitKey();
return 0;
}

