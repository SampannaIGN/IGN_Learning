# def fun1():
#     print("fun1")

# fun2 = fun1
# fun2()
def decorating_fun(fun):
    def new_fun():
        print("Before function")
        fun()
        print("After function")
    return new_fun

@decorating_fun     #try to comment and uncomment and see result
def fun():
    print("Function to be decorated")

fun()