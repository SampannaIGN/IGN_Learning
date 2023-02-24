'''
1)Write a program to display user entered name followed by "Good after noon"
2)Write a program to fill in a letter template given below with name and date
=> letter =  "Dear <|NAME|> you are selected! Date:<|DATE|>"
3)Write a program to detect double spaces in a string
4)Write a program to replace double spaces from string to single spaces
'''

def pbm1():
    name = input('Enter your name = ')
    return "Good afternoon "+name

def pbm2(my_str):
    my_str = str(my_str)
    name = input('Enter your name = ')
    date = input('Enter date = ')
    my_str = my_str.replace("<|NAME|>",name)
    my_str = my_str.replace("<|DATE|>",date)
    return my_str

def pbm3(my_str):
    my_str = str(my_str)
    isSpaceThere = False if my_str.find("  ")==-1 else True
    return isSpaceThere

def pbm4(my_str):
    my_str = str(my_str)
    return my_str.replace("  "," ")

#print(pbm1())

# my_str = '''Dear <|NAME|> you 
# are selected! 
# Date : <|DATE|>
# '''
# print(pbm2(my_str))

# my_str = "something is going wrong somewhere"
# print(pbm3(my_str))

# my_str = "something is  going wrong    somewhere"
# print(pbm4(my_str))

