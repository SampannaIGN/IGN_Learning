square = lambda x:x*x
sum = lambda x,y,z:x+y+z
joinStr = lambda list,str:str.join(list)#join can be used for any iterable type  

print(square(10))
print(sum(10,20,50))
print(joinStr(["abc","def","ghi"]," *** "))