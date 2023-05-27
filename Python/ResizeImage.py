import cv2

# Load the image
img = cv2.imread('/home/sampannat/Downloads/Learning/Python/Img.jpg')

# Resize the image
resized_img = cv2.resize(img, (864,128))

# Save the resized image
cv2.imwrite('./resized_image.jpg', resized_img)
