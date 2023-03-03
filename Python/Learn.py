print("***********STRING*************")
my_str = "  abc de   fh   "
print(my_str.find("de"))
print(my_str.replace("c","X"))
print(my_str.split(" "))
print(my_str.strip())#strips white spaces or new line before and after str


print("***********LIST*************")
l = [3,4,4,4,2,5]
l.remove(4)#removes first 4
#l.pop(4)
print(l)
l.insert(0,1)#inserts 1 at 0th index
print(l)
l.sort()#sorts the list
print(l)
print(max(l))
new_l = [1,3,3]
for i,item in enumerate(l):
    print(i,item)

print("***********TUPLE*************")
t = {1,3,1,6,2,4}#values in tuple can't be modified
print(t)


print("***********DICTIONARY*************")
d = {1:10,3:30}
new_d = {5:50,4:40}
d[2] = 20
d.update(new_d)
print(f"keys = {list(d.keys())}")
print(f"values = {list(d.values())}")
print(f"size = {len(d)}")
print(d.get(30))#doesn't throw error as 30 key is not present in the dictionary
d.pop(3)#element with key 3 is removed from the list
for keys in d:
    print(f"{keys} = {d[keys]}")

print("***********SET*************")

s = set()
s.add(10)
s.add(30)
s.add(30)
s_new = {1,2,7,7}
s.update(s_new)
print(s)
s.remove(30)
print(s)

print("**********ESSENTIAL LIB**********")
import math
import random
import os

print(os.listdir("."))#lists all the dir within specified path
#os.path.isdir(Path_str)#tells if given path is of folder
#os.path.isfile(Path_str)#tells if given path is of file
print(math.ceil(2.3))
print(math.floor(3.9))
print(math.modf(10.3))#separates values before and after point
print(math.sqrt(234.2))
print(f"loge(12)={math.log(12)} , log2(12)={math.log2(12)} , log10(12)={math.log10(12)}")
print(math.pow(3.2,2.3))
print("random vlaue between 2 & 10 = "+str(random.randint(2,10)))
print("random value between "+str(random.uniform(3,7.2)))

print("**********NORMAL FUNCTIONS*******")
print(abs(-234.2))
print(sum([2,3,7]))
print(max([3,7,9,5]))
print(len("abcd"))

print("***********DEQUE*********")
import collections

ll = collections.deque()
ll.append(10)
ll.appendleft(20)
ll.append(30)
print(ll)
#print(ll.popleft())#pops first element
#print(ll.pop())#pops last element
print(ll[len(ll)-1])
    # @property
    # def x(self):
    #     print("getter x")
    #     return self._x

    # @x.setter
    # def setX(self,x):
    #     print("setter x")
    #     self._x = x

# if __name__ == "__main__":
