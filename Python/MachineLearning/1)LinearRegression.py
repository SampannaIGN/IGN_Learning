import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets
from sklearn import linear_model
from sklearn.metrics import mean_squared_error

diabetes = datasets.load_diabetes() 
#print(diabetes)
#print(diabetes.keys())
#['data', 'target', 'frame', 'DESCR', 'feature_names', 'data_filename', 'target_filename', 'data_module']


#trying to check content of all the keys
#print(diabetes.data)
#print(diabetes.target)
#print(diabetes.frame)
#print(diabetes.DESCR)
#print(diabetes.feature_names)#['age', 'sex', 'bmi', 'bp', 's1', 's2', 's3', 's4', 's5', 's6'] are the features

#print(diabetes.data[:,np.newaxis,3])
'''
considers only column 3 elements and returns 2d numpy array
Ex :[[1,2,3,4],[5,6,7,8],[9,10,11,12]]  => [[3],[7],[11]]
in our case we have 10 columns for features like age,sex.... and 442 rows i.e no. of records

Let's consider only one feature for the sake of plotting
So that we can see the line easily... Because as feature increases the line changes to plane and so on...
which can't plotted
'''

inp_data = diabetes.data[:,np.newaxis,3]#only one feature
#inp_data = diabetes.data[:,[0,1,3,4,5,6,9]]#any random feature
#inp_data = diabetes.data[:,0:10]#all feature

#Comment/uncomment one of the above 3 line for only considering one feature
#Let's consider feature 'bp' which is feature number 3 & first 412 data for training
diabetes_x_train = inp_data[:-30]#2D
#Let's consider only last 20 for testing
diabetes_x_test = inp_data[-20:]#2D

#Let's see, what the output label should be for first 412 data
diabetes_y_train = diabetes.target[:-30].reshape(412,1)#2D Even if reshape not used it will work
#Let's see, what the output label should be for last 20 test data
diabetes_y_test = diabetes.target[-20:].reshape(20,1)#2D Even if reshape not used it will work

#Target is a 1D numpy array which has 442 records
#i.e it gives ouput for every row of the input data
model = linear_model.LinearRegression()
model.fit(diabetes_x_train,diabetes_y_train)
diabetes_y_predict = model.predict(diabetes_x_test)

print(f"Mean square error = {mean_squared_error(diabetes_y_test,diabetes_y_predict)}")
#Basically does sqrt((error1^2+error2^2+error3^2+...+errorN^2)/N)

#y = mx+c or y = w0+w1x1
print("weights = ", model.coef_)#w1
print("intercept = ", model.intercept_)#w0


#plotting test data

# plt.scatter(diabetes_x_test,diabetes_y_test.ravel())#since use reshape for y_test
# plt.plot(diabetes_x_test,diabetes_y_predict.ravel())#since used reshape for y_predict
# plt.show()
