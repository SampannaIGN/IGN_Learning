def my_function():
    print("my_function")

class my_class():
    cls_attr = "cls_attr"

    def __init__(self):
        print("Constructor")

    def method1(self):
        print("method1")

if __name__ == "__main__":
#Making sure that if other module imports this module then following code won't run
    my_function()
    obj = my_class()
    obj.method1()