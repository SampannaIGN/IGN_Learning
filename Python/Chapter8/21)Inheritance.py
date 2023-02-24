#Possible type of inheritance are single,multi-level,multiple
class Parent:
    parentStatic = "parentStatic"

    def __init__(self):
        print("Parent constructor")

    def parentMethod(self):
        print("Parent Method")

    def methodToOverride(sefl):
        print("Parent method methodToOverride")

class Child(Parent):
    childStatic = "childStatic"

    def __init__(self):
        print("Child Constructor")
        super().__init__()
    
    def childMethod(self):
        #also possible => super().__init__()
        #also possible => self.__init__()
        print("Child method")

    def methodToOverride(sefl):
        super().methodToOverride()
        print("Child method methodToOverride")

obj = Child()
obj.parentMethod()
obj.methodToOverride()
obj.childMethod()
print(obj.childStatic)
print(obj.parentStatic)