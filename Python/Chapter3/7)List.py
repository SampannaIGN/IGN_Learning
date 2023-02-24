
list = [12,5,3,7]
print(list)             #print all elements of list     => [12,5,3,7]
print(list[0])          #access first element in list   => 12
list[3] = 99            #change value of list           
print(list)             #print all elements of list     => [12,5,3,99]

print("*******")
list = ["abc",10,False,1.4,"nothing"]
print(list)             #or print(list[:])          => ["abc",10,False,1.4,"nothing"]
print(list[:3])         #["abc",10,False]           => ["abc",10,False]
print(list[::2])        #["abc",False,"nothing"]    => ["abc",False,"nothing"]

print("*******")
list = [6,9,5,7,4,2,1]
list.sort()             #sorts the list             
print("sort() = "+str(list))                        #=> [1,2,4,5,6,7,9]
list.reverse()          #reverses the list
print("reverse() = "+str(list))                     #=> [9,7,6,5,4,2,1]
list.append(20)         #adds to the end of list
print("append(20) = "+str(list))                    #=> [9,7,6,5,4,2,1,20]
list.insert(3,21)       #inserts 21 @ index=3
print("insert(3,21) = "+str(list))                  #=> [9,7,6,21,5,4,2,1,20]
list.pop(2)             #removes value from index=2
print("pop(2) = "+str(list));                       #=> [9,7,21,5,4,2,1,20]
list.remove(7)          #removes element 7
print("remove(7) = "+str(list))                     #=> [9,21,5,4,2,1,20]
print(len(list))                                    #=> 7
