import matplotlib.pyplot as plt
import numpy as np
from sklearn import linear_model

x_train = np.array([[1],[2],[3]])
y_train = np.array([3,2,4])

x_test = np.array([[-20],[-10],[-2],[-1],[6],[10],[20]])

model = linear_model.LinearRegression()
model.fit(x_train,y_train)

y_predict = model.predict(x_test)

print(f"Intercept = {model.intercept_}")
print(f"Slope = {model.coef_}")

plt.scatter(x_train,y_train)
plt.plot(x_test,y_predict)
plt.show()