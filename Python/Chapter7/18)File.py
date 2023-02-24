fInput = open('Sample1.txt')#if file doesn't exist it will throw error
# or fInput = open('Sample.txt','r') => r->read w->write a->append +->update 
# rb->read in binary mode rt->read in text mode
# print(fInput.read()) => Reads entire fInputile
# print(fInput.read(10)) => Reads fInputirst 10 characters ofInput the fInputile 
content = ""
while True:
    content = fInput.readline()

    if(content != ""):
        print(content.strip())
        continue
    else:
        break

fInput.close()

#Overriding the file content
fOutput = open('Sample2.txt','w')#If file doesn't exist it creates new file
fOutput.write('''I am writing
something crazy
''')
fOutput.write("This is it\nThis is it.")

fOutput.close()

#Appending to the file
fOutput = open('Sample2Append.txt','a')
fOutput.write('writing\n')
fOutput.close()



# with open('fileName.txt','r') as f:
#     a = f.read()
#     print(a)
# => Using above syntax f will automatically close()