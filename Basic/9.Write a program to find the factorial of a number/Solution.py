def factorial(n):
    fact = 1
    for i in range(1, n + 1):
        fact *= i
    return fact

if __name__ == "__main__":
    n = int(input("Enter a number: "))

    if n < 0:
        print("Factorial is not defined for negative numbers.")
    else:
        print(f"Factorial of {n} is {factorial(n)}")
