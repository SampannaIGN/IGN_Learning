import matplotlib.pyplot as plt


plt.title('Graph')
plt.xlabel('x-axis')
plt.ylabel('y-axis')

x=[]
y=[]

for i in range(-10,20):
    x.append(i)
    y.append(-i+2)


plt.plot(x,y)
plt.grid()
plt.show()


# import keras
# from keras.models import Sequential
# from keras.layers import Dense, Activation

# model = Sequential([Dense(5,input_shape=(3,),activation='relu')])
# model.add(Dense(5,input_shape=(3,)))
# model.add(Activation('relu'))