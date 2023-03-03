from sklearn import datasets
from sklearn.linear_model import LogisticRegression
import numpy as np
import matplotlib.pyplot as plt

# 0->Iris-Setosa
# 1->Iris-Versicolour
# 2->Iris-Virginica

def npArrayToBinary(array,index):
    for i,value in enumerate(array):
        if array[i]==2:
            array[i] = 1
        else:
            array[i] = 0
    return array


iris = datasets.load_iris()
# print(iris.data)
X = iris["data"][:,2:3]#will return 2D with each element of 1D having 2nd col data
#X = iris["data"][:,2] will return 1D array from col 2 of iris data
Y = npArrayToBinary(iris["target"],2)
model = LogisticRegression()
model.fit(X,Y)
ex1 = model.predict([[1.7]])
ex2 = model.predict([[5.7]])

#for plotting let's take some other test cases
xTest = np.linspace(3.5,6,1000)#1000 equally spaced values between 0 & 3
xTest = xTest.reshape(len(xTest),1)
yPredict = model.predict_proba(xTest)
plt.plot(xTest.ravel(),yPredict[:,0].ravel())
plt.scatter(X.ravel(),Y.ravel())
plt.show()
