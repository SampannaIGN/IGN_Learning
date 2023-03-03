def computeOutput(input,coeff):
    output = []

    for i in range(0,len(input)-len(coeff)+1):
        sum = 0
        coeff_index = 0
        for j in range(i,i+len(coeff)):
            sum += input[j]*coeff[coeff_index]
            coeff_index += 1
        output.append(sum)
    
    return output

input = []
coeff = []

for i in range(0,100):
    input.append(i)

for i in range(1,5):
    coeff.append(i)

output = computeOutput(input,coeff)

print(f"input(len={len(input)})")
print(input)
print(f"coeff(len={len(coeff)})")
print(coeff)
print(f"output(len={len(output)})")
print(output)