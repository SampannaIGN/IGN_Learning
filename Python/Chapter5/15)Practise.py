'''
1) multiplication of given number using for loop
2) Greet all the strings starting with 's'
3) pbm1 using while loop
4) Check whether number is prime or not
5) Sum of first n natural numbers using while
6) Compute factorial of given number
7) Print pyramid * pattern
'''

import math
def pbm1():
    value = int(input("Enter a number whose multiplication table has to be created = "))
    for i in range(1,11):
        print(f"{value} * {i} = {value*i}")#print(str(value)+" * "+str(i)+" = "+str(value*i))

def pbm2():
    list = ["Sam","Sudhir","suresh","mohith"]

    for item in list:
        if item.startswith('S') or item.startswith('s'):
            print("Greetings Mr/Ms. "+item.capitalize())

def pbm3():
    value = int(input("Enter a number whose multiplication table has to be created = "))
    i = 1
    while i <= 10:
        print(f"{value} * {i} = {value*i}")#print(str(value)+" * "+str(i)+" = "+str(value*i))
        i = i+1

def pbm4():
    value = int(input("Enter a value to check if it is prime = "))
    if value >= 2:
        for i in range(2,int(math.sqrt(value))+1):
            if(value%i == 0):
                print("It is not a prime")
                break
        else:
            print("It is a prime")
    else:
        print("It is not a prime")

'''
Reason for iterating from 2 to sqrt(n) is because =>

if n = a*b 
here either a>b  then b<sqrt(n)<a 
or          a<b  then a<sqrt(n)<b
or          a==b then a=b=sqrt(n)

that means one of the two i.e a or b will be always less than
or equal to sqrt(n) in case it is divisible by n hence 2 to sqrt(n)

'''

def pbm5():
    value = int(input('Enter a value to compute sum of n number = '))
    sum = 0
    while value>=1:
        sum = sum + value
        value = value-1
    print("Sum = "+str(sum))

def pbm6():
    value = int(input('Enter a value ot computer factorial of n = '))
    fact = 1
    while value>=1:
        fact = fact*value
        value = value-1
    print("Factorial is "+str(fact))

def pbm7():
    row = int(input('Enter the height of pyramid'))

    for i in range(row):
        for j in range(row-i-1):
            print(" ",end="")
        for j in range(i*2+1):
            print("*",end="")
        print()



# pbm1()
# pbm2()
# pbm3()
# pbm4()
# pbm5()
# pbm6()
# pbm7()