'''
1)store 7 fruits name entered by user into list
2)accept marks of 6 students and display in sorted order
3)get sum of all elements of the list
4)count number of 0's in a tuple
'''

def pbm1(list):
    fruit1 = input("Enter fruit 1 = ")
    fruit2 = input("Enter fruit 2 = ")
    fruit3 = input("Enter fruit 3 = ")
    fruit4 = input("Enter fruit 4 = ")
    fruit5 = input("Enter fruit 5 = ")
    fruit6 = input("Enter fruit 6 = ")
    fruit7 = input("Enter fruit 7 = ")
    list.append(fruit1)
    list.append(fruit2)
    list.append(fruit3)
    list.append(fruit4)
    list.append(fruit5)
    list.append(fruit6)
    list.append(fruit7)
    return list

def pbm2(list):
    mark1 = input("Enter mark 1 = ")
    mark2 = input("Enter mark 2 = ")
    mark3 = input("Enter mark 3 = ")
    mark4 = input("Enter mark 4 = ")
    mark5 = input("Enter mark 5 = ")
    mark6 = input("Enter mark 6 = ")
    list.append(mark1)
    list.append(mark2)
    list.append(mark3)
    list.append(mark4)
    list.append(mark5)
    list.append(mark6)
    list.sort()
    return list

def pbm3(list):
    return sum(list)

def pbm4(tuple):
    return tuple.count(0)

#print(pbm1([]))
#print(pbm2([]))
#print(pbm3([3.4,5,2.8,7]))
#print(pbm4((1,2,0,3,0,0,0)))
