def fibonacci(n):
    first, second = 0, 1

    print("Fibonacci Series: ", end="")
    for _ in range(n):
        print(first, end=" ")
        first, second = second, first + second
    print()

# Input from the user
n = int(input("Enter the number of terms: "))

if n <= 0:
    print("Please enter a positive integer.")
else:
    fibonacci(n)
