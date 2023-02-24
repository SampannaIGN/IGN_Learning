list = [3,2,6,7,9,10,2,6,7]
even_list = [i for i in list if i%2==0]
unique_set = {i for i in list}

value = int(input("Enter a value to compute multiplication table = "))
multiplication_table = [value*i for i in range(1,11)]

print(even_list)
print(unique_set)
print(multiplication_table)