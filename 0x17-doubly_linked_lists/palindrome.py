def is_palindrome(n):
    # Convert the number to a string and check if it's equal to its reverse
    return str(n) == str(n)[::-1]

largest_palindrome = 0

# Iterate through all possible combinations of two 3-digit numbers
for i in range(100, 1000):
    for j in range(i, 1000):
        product = i * j
        if is_palindrome(product) and product > largest_palindrome:
            largest_palindrome = product

# Save the result to the file
with open('102-result', 'w') as file:
    file.write(str(largest_palindrome))

print("Largest palindrome:", largest_palindrome)
print("Result saved to 102-result file.")
