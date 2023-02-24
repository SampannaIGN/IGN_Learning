my_set = {5,2,2,3,4,4,4,1}
print(my_set)#=>{3,2,(3,1,2),8}  

my_set = {}#by deafult it is taken as dictionary
print(type(my_set))#=><class 'dict'>

my_set = set()#to create empty set we use this
print(type(my_set))#=><class 'set'>

my_set.add(6)
my_set.add(3)
my_set.add(2)
my_set.add(2)
my_set.add((3,1,2))
my_set.add(8)
#can't add list,dictionary into set... Only tuple can be added as it can't be changed
#can't change items in set

print("set after adding elements = "+str(my_set))
#=>{2, 3, 6, 8, (3, 1, 2)}
print("length of the set is "+str(len(my_set)))
#=>5
my_set.remove(6)#removes 6
print("set after removing 6 = "+str(my_set))
#=>{2, 3, 8, (3, 1, 2)}  
print("arbitrary removal = "+str(my_set.pop()))#removes an arbitrary value from set
#=>can't predict... Let's say {3, 8, (3, 1, 2)}

union_set = my_set.union({2,9})
intersection_set = my_set.intersection({3,2,1})

print("union set = "+str(union_set))# {3,8,(3,1,2)} U {2,9} =>{2,3,(3,1,2),8,9}
print("intersection set = "+str(intersection_set))# {3,8,(3,1,2)} Intersection {3,2,1} =>{3}
