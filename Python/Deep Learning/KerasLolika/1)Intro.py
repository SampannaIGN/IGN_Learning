from sklearn import datasets
import matplotlib.pyplot as plt

import keras
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import Dropout
from kerastuner.tuners import RandomSearch


def npArrayToBinary(array,index):
    for i,value in enumerate(array):
        if array[i]==2:
            array[i] = 1
        else:
            array[i] = 0
    return array

def compareCount(list1,list2):
    count = 0
    for i in range(len(list1)):
        if (list1[i]==list2[i]):
            count+=1
    return count

iris = datasets.load_iris()
# print(iris.data)
#print(iris.feature_names)
#print(len(iris.data))
#print(len(iris.feature_names))
X = iris["data"][:,:]#will return 2D with each element of 1D having 2nd col data
#X = iris["data"][:,2] will return 1D array from col 2 of iris data
#print(iris["target"])
Y = npArrayToBinary(iris["target"],2)#verginica or not


model = Sequential()
model.add(Dense(units = 6,kernel_initializer='he_uniform',activation='relu',input_dim=4))
'''
first hidden layer has 6 neurons
for relu activation function => he_uniform,he_normal works well
input_dim tells how many inputs are given...
'''
model.add(Dense(units = 6,kernel_initializer='he_uniform',activation='relu'))
#added one more hidden layer with 6 neurons

model.add(Dense(units=1, kernel_initializer='glorot_uniform',activation='sigmoid'))
#adding last layer with sigmoid activation function as o/p is either 0 or 1
model.compile(optimizer='adam',loss='binary_crossentropy',metrics=['accuracy'])
'''
whenever output is 0 or 1 => binary_crossentropy
whenever output is multiclass i.e. 0,1,2,.. =>categorical_crossentropy
'''
model.summary()
#gives the summary of the model created

model_info = model.fit(X,Y,batch_size=10,epochs=100)
#print(X)
print(model.predict(X))
'''
my_list = model.predict(X).ravel()
prediction = list(map(lambda y:int(y>0.5),my_list))
print(prediction)
print(f"Total output count = {len(Y)}")
print(f"Correct predition = {compareCount(prediction,Y)}")
print(f"Wrong prediction = {len(Y)-compareCount(prediction,Y)}")
'''
#print(model.predict([[5.1,3.5,1.4,0.2]]))

# [5.9,3.,5.1,1.8] =>verginica
# [5.1,3.5,1.4,0.2] =>not verginica
# print(model.predict())
# plt.plot(model.history['acc'])
# plt.plot(model.history['val_acc'])
# plt.tile('modle accuracy')
# plt.ylabel('accuracy')
# plt.xlabel('epochs')
# plt.legend(['train','test'],loc='upper left')
# plt.show()
