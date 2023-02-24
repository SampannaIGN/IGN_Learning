my_dic = {
    "key1" : "value1",
    "key2" : "value2"
}

print("key value pair before updatation = "+str(my_dic)+"\n")
#{"key1":"value1","key3":"value3"}

new_dic = {
    "key4" : "value4",
    "key5" : "value5"
}

my_dic.update(new_dic)

print("key value pair after updation = "+str(my_dic)+"\n")
#{"key1":"value1","key2":"value2","key4":"value4","key5":"value5"}
print("values are = "+str(list(my_dic.values()))+"\n")
#["value1","value2","value4","value5"]
print("keys are = "+str(list(my_dic.keys()))+"\n")
#["key1","key2","key4"]
print("list key value tuples = "+str(my_dic.items())+"\n")
#dict_items([("key1","value1"),("key2","value2"),("key4","value4"),("key5","value5")])

print("get(key1) = "+str(my_dic.get("key1"))+"\n")#doesn't throw error if key doesn't exists instead returns None
#"value1"
print("my_dic[key1] = "+str(my_dic["key1"])+"\n")#throws error if key doesn't exists
#"value1"
print("length = "+str(len(my_dic))+"\n")
#4

for key in my_dic:
    print(str(key)+" = "+my_dic.get(key))