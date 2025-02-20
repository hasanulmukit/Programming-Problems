def sum_of_digits(num):
    sum = 0
    while num != 0:
        sum += num % 10  # Get the last digit
        num //= 10       # Remove the last digit
    return sum

if __name__ == "__main__":
    num = int(input("Enter a number: "))
    print(f"Sum of the digits: {sum_of_digits(num)}")
