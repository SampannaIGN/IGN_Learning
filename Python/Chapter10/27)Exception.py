#Part1
str_input = input("Enter a value")

try:
    value = int(str_input)
    print(1/0)
except ValueError as v:
    print("ValueError occured")#when str_input can't be typecasted
except ZeroDivisionError as z:
    print("ZeroDivisionError occured")#when tried to divide by 0
except Exception as e:
    print("Exception occured")
    print("Error info = "+str(e.args))
except:#Any exception other than ValueError, ZeroDivisionError and Exception
    print("any other Excpetion")


#Part2

try:
    value = int(str_input)
except:
    raise ValueError("Value Error raised")
else:#executed only if try works successfully
    print("Try executed successfully")


try:
    value = int(str_input)
except:
    raise ValueError("Value Error raised")
finally:#executed always even if exception occurs or not
    print("Try executed successfully")