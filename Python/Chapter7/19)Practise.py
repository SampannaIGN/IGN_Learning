'''
Write a program to rename a file
Write a program to list all the files/folders in a given folder
'''
import os

def rename(oldName,newName):
    content = ""

    with open(oldName,'r') as f:
        content = f.read()

    with open(newName,'w') as f:
        f.write(content)

    os.remove(oldName)

def listDir(path,list):
    entries = os.listdir(path)

    for value in entries:
        if("." not in value):
            listDir(path+"/"+value,list)
        else:
            list.append(path+"/"+value)
    
    return list
        
#rename("Sample2.txt","Sample1.txt")
print(listDir(".",[]))




