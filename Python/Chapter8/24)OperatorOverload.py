class Number:

    def __init__(self,x):
        self._x = x

    def __add__(self,obj2):
        return self._x+obj2._x
    
    def __sub__(self,obj2):
        return self._x-obj2._x

    def __mul__(self,obj2):
        return self._x*obj2._x
    
    def __truediv__(self,obj2):
        return self._x/obj2._x
    
    def __floordiv__(self,obj2):
        return self._x//obj2._x

    def __str__(self):
        return str(self._x)  

    def __len__(self):
        return len(str(self._x))

n1 = Number(10.5)
n2 = Number(20.6)
sum = n1+n2
diff = n1-n2
mul = n1*n2
div = n1/n2
floorDiv = n1//n2 # similar to integer division
print(sum)
print(diff)
print(mul)
print(div)
print(floorDiv)
print(len(n1))