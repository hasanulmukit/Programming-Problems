def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

# Input from the user
n = int(input("Enter the number of terms: "))

# Output the Fibonacci series
print("Fibonacci series:")
for i in range(n):
    print(fibonacci(i), end=" ")
print()
