import matplotlib.pyplot as plt
import numpy as np
import math

#eq = (x-h)2 + (y-k)2 = r2

def getMeY(x,r):
    return math.sqrt((r*r)-(x*x))

r = 2
x = np.linspace(-r,r,1000)
y = []

for i in range(len(x)):
    y.append(getMeY(x[i],r))


plt.plot(x,y)
for i in range(len(y)):
    y[i] = -y[i]
plt.plot(x,y)
plt.show()
