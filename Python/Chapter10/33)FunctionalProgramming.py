#map => used when a function needs to be applied for all items

my_list = [2,4,9,10,17]
square = lambda x:x*x
my_list = list(map(square,my_list))
print(my_list)

#filter => filters value based on boolean function

my_list = [2,7,3,6,4,4,7,8,9]
is_even = lambda value:value%2==0

my_list = list(filter(is_even,my_list))
print(my_list)

#reduce => used to accumulate values
my_list = [2,4,5,6,8,10]
from functools import reduce

sumfor2 = lambda x,y:x+y 
total = reduce(sumfor2,my_list)
print(total)