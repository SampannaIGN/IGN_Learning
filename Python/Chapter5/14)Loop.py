list = [1,3,5,9,7,2,6]
list.sort()

i=0
print("Printing list using while loop")
while i<len(list):
    print(list[i],end=" ") 
    i=i+1

print()

print("\nPrinting list using for loop")
for item in list:
    print(item,end=" ")

print("\n\nusing for loop with range 0-4")
for i in range(4): #or for i in  range(0,4)
    print(i,end=" ")

print("\n\nusing for loop with range 2-4 with else")
for i in range(2,4):
    print(i,end=" ")
else:
    print("***else executed")


print("\n\nusing for loop with range 2-7 with break")
for i in range(2,7):
    print(i,end=" ")
    if i==5:
        break
else:
    print("***else executed")

#if for loop breaks because of break statement then else won't be executed
#But if for loop doesn't encounter break then else will be executed

print("\n\nUsing for loop with range 2-7 with continue at 3 with else")
for i in range(2,7):
    if i == 3:
        continue
    print(i,end=" ")
else:
    print("***else executed")


#   pass is a dummy statement in python that doesn't perform any operation
#
# def fun():
#     pass

# if 10==10:
#     pass

# while 10>2:
#     pass

