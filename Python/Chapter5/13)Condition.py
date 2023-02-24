a = int(input('Enter a value = '))

if(a<5):
    print("Lesser than 5")
elif(a>=5 and a<=10):
    print("Between 5 and 10")
else:
    print("Greater than 10")

a = None

if(a==None):
    print("using ==")

if(a is None):#It is like null in other programming languages
    print("using is")

a = (2,10)

if 20 not in a:
    print("20 is not present in a")

