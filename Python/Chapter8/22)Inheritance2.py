#Multiple inheritance

class Parent1:
    parentStatic = "abc"

    def __init__(self) -> None:
        print("Parent1 constructor")

    def fun1(self):
        print("Parent1 function")

class Parent2:
    parentStatic = "def"

    def __init__(self) -> None:
        print("Parent2 constructor")

    def fun1(self):
        print("Parent2 function")

class Child(Parent1,Parent2):#Change order and try
    
    def __init__(self) -> None:
        super().__init__() # As Parent2 has high priority because of the ordering it will be called
        print("Child constructor")

    def fun1(self):
        super().fun1()

obj = Child()
print(obj.parentStatic)#Based on the order in which Parent2 & Parent1 are inherited
obj.fun1()