import numpy as np

def fir_filter(signal, coefficients):
    """
    Applies a 1D FIR filter to the input signal using the given coefficients.
    """
    output = np.zeros(len(signal))
    for i in range(len(signal)):
        for j in range(len(coefficients)):
            if i >= j:
                output[i] += coefficients[j] * signal[i-j]
    return output

input = []
coeff = []

for i in range(96):
    input.append(i)

for j in range(1,5):
    coeff.append(j)

print(input)
print(coeff)

result = fir_filter(input,coeff)
print(result)
