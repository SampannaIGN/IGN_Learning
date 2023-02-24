# Different ways to hold string values
# str = 'abc' => usefull when double quotes are a part of string
# str = "abc" => usefull when single quotes are a part of string
# str = '''abc''' => usefull when both single and double quotes & next line is a part of string

myString = "abcdefghijkl"
print(myString[1])#=>b
print(myString[0:3])#or print(myString[:3]) => "abc"
print(myString[1:12])#or print(myString[1:]) =>"bcdefghijkl"
print(myString)#or print(myString[:]) => "abcdefghijkl"
print(myString[0:12:2])#or print(myString[::2]) => "acegik"
print(myString[::3])#or print(myString[0:12:3]) => "adgj"
print(myString[-1::-1])#-1 is the index of l so it starts printing in back direction
#=>"lkjihgfedcba"
print(myString[-3:])#=>"jkl"
#myString[1] = 'a' => not possible


print("*******")
#string functions
myString = "hi!!! There are a lots of things to think about."
print(len(myString))#returns the length of the string => 48
print(myString.endswith("jkl"))#returns true if the string ends with "jkl"=>false
print(myString.capitalize())
#Capitalizes the first character => "Hi!!! There are a lots of things to think about."
print(myString.count("i"))#***Returns number of times i occured => 3
print(myString.find("The"))
#***Returns index of first occurence of The. 
# if The doesn't exist then it returns -1 => 6
print(myString.replace("t","X"))#***Replaces where ever t is there to X
#=>"hi!!! There are a loXs of Xhings Xo Xhink abouX."
print(myString.upper())#***Converts string to upper case
#=>"HI!!! THERE ARE A LOTS OF THINGS TO THINK ABOUT."
print(myString.lower())#***Converts string to lower case
#=>"hi!!! there are a lots of things to think about."
#Note: to replace some characters with some other characters at given index we do following

print("*******")
myString = "0123452"#in this case if I want to replace 2 at index 2  to 'X' then I can do as below
myString = myString[:2]+'X'+myString[3:];#*** 2 replaced by X
print(myString)