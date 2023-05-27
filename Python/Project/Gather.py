import tensorflow as tf

# Define a tensor of shape (4, 3)
x = tf.constant([[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]])

# Define a tensor of indices to gather
indices = tf.constant([1, 3, 0])

# Use tf.gather to retrieve the elements from x based on the indices
result = tf.gather(x, indices)

# Print the result
print("Result is =",end=' ')
print(result)

