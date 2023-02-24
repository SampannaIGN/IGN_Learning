'''
1) Write a program to create dictionary of hindi words with it's meaning as value.
Also try printing and try to retrieve the values for a particular key.
2) Write a program to input four numbers from the user and display all the unique
numbers once.
3) Can we have my_set with 18 and "18" => Ans=> {18,'18'}
4) What will be the length of following my_set s:
s = my_set()
s.add(20)
s.add(20.0)
s.add("20") 
=>2 i.e. (20,'20')
5) s = {} what is the type of s? => dictionary
6) If you insert similar key into dictionary what will happen? => lastly added key 
will be considered
7) Can dictionary contain similar values? => Yes
8) Can you add list into set? => No

'''

def pbm1():
    my_dic = {
        "mai" : "I",
        "kya" : "what"
    }
    my_dic["kam"] = "less"
    print(my_dic.items())
    print("first item 'mai' value is "+str(my_dic.get("mai")))

def pbm2():
    value1 = input('Enter value 1 = ')
    value2 = input('Enter value 2 = ')
    value3 = input('Enter value 3 = ')
    value4 = input('Enter value 4 = ')
    
    my_set = set()
    my_set.add(value1)
    my_set.add(value2)
    my_set.add(value3)
    my_set.add(value4)

    print(my_set)

#pbm1()
#pbm2()
my_set = set();
my_set.add(20)
my_set.add(20.0)
my_set.add("20")
print(my_set)