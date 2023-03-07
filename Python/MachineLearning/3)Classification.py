from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier
import numpy as np

def get_input(size):
    input_list = []
    for i in range(1,size+1):
        input_list.append(float(input("Enter feature{i} = ")))

    return np.array(input_list).reshape(1,size)

iris = datasets.load_iris()

print(iris.data)
print(iris.target)
#=>dict_keys(['data', 'target', 'frame', 'target_names', 'DESCR', 'feature_names', 'filename', 'data_module'])
#print(type(iris.target_names))
#=>['setosa' 'versicolor' 'virginica']

feature = iris.data     #150 records are present each record has 4 features(2D array)
label = iris.target     #150 labels are present(1D array)

classifier = KNeighborsClassifier()
classifier.fit(feature,label)

prediction = classifier.predict(get_input(4))

print(iris.target_names[prediction])