#tuple can't be modified
tuple = (5,7,8,6,7,7)
print(tuple.count(7))   #3
print(tuple.index(8))   #2
print(len(tuple))       #6
print(tuple)            #(5,7,8,6,7,7)
print(tuple[3])         #6
#tuple[0] = 2 => not possible as it is immutable 
