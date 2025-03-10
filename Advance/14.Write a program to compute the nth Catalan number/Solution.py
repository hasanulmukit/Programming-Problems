def factorial(n):
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result

def catalan_number(n):
    numerator = factorial(2 * n)
    denominator = factorial(n + 1) * factorial(n)
    return numerator // denominator

if __name__ == "__main__":
    n = int(input("Enter the value of n: "))
    print(f"The {n}th Catalan number is: {catalan_number(n)}")
