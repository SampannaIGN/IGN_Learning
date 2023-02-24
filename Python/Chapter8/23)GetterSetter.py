class Employee:
    def __init__(self,x,y):
        self._x = x #just saying that x is private but it can be modified
        self._y = y #just saying that y is private but it can be modified

    #if there are any variables who's value depends on value of other variable
    #then it's better to make it a property(acts as instance variable)
    #property is basically an instance variable which when called or used performs
    #the operation provided
    #It is also called getter
    @property
    def x(self):
        print("getter x")
        return self._x

    @property
    def y(self):
        print("getter y")
        return self._y

    @x.setter
    def setX(self,x):
        print("setter x")
        self._x = x

    @y.setter
    def setY(self,y):
        print("setter y")
        self._y = y

obj = Employee(10,25)
obj.setX = 5            #setter x called
obj.setY = 6            #setter y called
print(obj.x)            #getter x called
print(obj.y)            #getter y called

