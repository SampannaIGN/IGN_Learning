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
        if(os.path.isdir(path+"/"+value)):
            listDir(path+"/"+value,list)
        else:
            if(".cpp" in value or ".h" in value):
                list.append(path+"/"+value)
    
    return list

def getLineCount(fileList):
    total_line = 0
    for file in fileList:
        line = 0
        with open(file,'r') as f:
            while True:
                content = f.readline()
                if(content != ""):
                    line+=1
                else:
                    break
        print(f"fileName = {file}, lines = {line}")
        total_line += line

    print(f"total lines = {total_line}")
    return total_line
        
#rename("Sample2.txt","Sample1.txt")
fileList = listDir(".",[])
print(fileList)
getLineCount(fileList)

