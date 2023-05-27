from sklearn import datasets
import matplotlib.pyplot as plt

import keras
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import Dropout
from keras import layers
from kerastuner.tuners import RandomSearch

'''
Gives info on
1) How many number of hidden layers
2) How many number of neurons in each hidden layer
3) Learning rate
'''
def build_model(hp):
    model = keras.Sequential()

    for i in range(hp.Int('num_layers',2,20)):#trying out hidden layers anywhere b/w 2 to 20
        model.add(layers.Dense(units=hp.Int('units_'+str(i),min_value=32,max_value=512,step=32),activation='relu'))

    model.add(layers.Dense(1,activation='linear'))

    model.compile(optimizer=keras.optimizers.Adam(hp.Choice('learning_rate',
                [1e-2,1e-3,1e-4])),
                loss='mean_absolute_error',
                metrics = ['mean_absolute_error'])
    return model

'''
Actually 5*3=15 trials are done
'''
tuner = RandomSearch(
    build_model,
    objective='val_mean_absolute_error',
    max_trials=5,
    executions_per_trial=3,
    directory='ResultDir',
    project_name='DiabetesProject'
)
#tuner.search_space_summary()

diabetes = datasets.load_diabetes() 

x_train = diabetes.data[:-30]#2D
x_test = diabetes.data[-20:]#2D

y_train = diabetes.target[:-30].reshape(412,1)#2D Even if reshape not used it will work
y_test = diabetes.target[-20:].reshape(20,1)#2D Even if reshape not used it will work

tuner.search(x_train,y_train,epochs=5,validation_data=(x_test,y_test))
tuner.results_summary()