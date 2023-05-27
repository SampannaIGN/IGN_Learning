from sklearn import datasets
import matplotlib.pyplot as plt

from keras.wrappers.scikit_learn import KerasClassifier
from sklearn.model_selection import GridSearchCV

from keras.models import Sequential
from keras.layers import Dense, Activation,BatchNormalization, LeakyReLU, Dropout
from keras.activations import relu,sigmoid

def create_model(x,layers,activation):
    model = Sequential()

    for i,nodes in enumerate(layers):
        if i==0:
            model.add(Dense(nodes,input_dim=x.shape[1]))
            model.add(Activation(activation))
            model.add(Dropout(0.3))
        else:
            model.add(Dense(nodes))
            model.add(Activation(activation))
            model.add(Dropout(0.3))
    
    model.add(Dense(units=1,kernel_initializer='glorot_uniform',activation='sigmoid'))
    model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

    return model


model = KerasClassifier(build_fn=create_model,verbose=0)

layers = [[20],[20,10,20],[32,32,32,32],[16,32,16,16]]
activation = ['sigmoid','relu','LeakyReLU']

diabetes = datasets.load_diabetes() 
x_train = diabetes.data[:-30]
x_test = diabetes.data[-20:]
y_train = diabetes.target[:-30].reshape(412,1)
y_test = diabetes.target[-20:].reshape(20,1)

param_grid = dict(x=x_train,layers=layers,activation=activation,batch_size=[64,128,256],epochs=[10,20,30])
grid = GridSearchCV(estimator=model,param_grid=param_grid,cv=5)

grid_result = grid.fit(x_train,y_train)

print(grid_result.best_score_,grid_result.best_params_)

pred_y = grid.predict(x_test)