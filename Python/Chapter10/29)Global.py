global_variable = 20

def fun1():
    global_variable = 21#actually this is local variable

def fun2():
    global global_variable
    global_variable = 21


print(f"global variable value initially = {global_variable}")
fun1()
print(f"global variable value after calling fun1 = {global_variable}")
fun2()
print(f"global variable value after calling fun2 = {global_variable}")
