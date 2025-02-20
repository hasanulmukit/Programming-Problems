def check_prime_or_composite(num):
    if num <= 1:
        return "The number is neither prime nor composite."
    
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return "The number is composite."
    return "The number is prime."

if __name__ == "__main__":
    num = int(input("Enter a number: "))
    print(check_prime_or_composite(num))
