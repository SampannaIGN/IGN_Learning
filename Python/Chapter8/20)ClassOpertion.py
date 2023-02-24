# Constructor overloading not supported in python
# objects can't modify static attributes
class ClassName:
    classAttribute = "original class att"

    def __init__(self):
        self.att1 = 0   #initializing att1
        self.att2 = 0   #initializing att2
        print("Constructor")

    def instanceMethod(self,param1):
        print("instance method with this param => "+str(param1))

    @staticmethod
    def staticMethod(param1):
        ClassName.classAttribute = "new name to class attr from staticMethod"
        print("static method with this param => "+str(param1))

    #using static & class method we can modify class attributes value without instantiation
    #using cls we can access static class attributes
    #only difference between static method & classmethod is cls must be passed in classmethod
    @classmethod
    def classMethod(cls,param1):
        print("class method with cls param = "+cls.classAttribute)

    def __str__(self):
        return "Returns when object is printed"

obj1 = ClassName()
obj1.newAtt = "newAttValue"                 #is an instance attribute applicable only for obj1
obj1.classAttribute = "changed class att"   #Becomes instance attribute application for obj1

obj2 = ClassName()

print(obj1.newAtt)
print(obj1.classAttribute)
print(obj2.classAttribute+" or "+ClassName.classAttribute)
#print(obj2.newAtt) => Will give error

obj1.instanceMethod("param1")  #or ClassName.instanceMethod(obj1,10)
obj2.instanceMethod("param2")  #or ClassName.instanceMethod(obj2,"x")

ClassName.staticMethod("static param") 
ClassName.classMethod("class param")