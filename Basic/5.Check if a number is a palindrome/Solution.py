# Function to check if a number is a palindrome
def is_palindrome(num):
    original = num
    reversed_num = 0

    while num != 0:
        remainder = num % 10
        reversed_num = reversed_num * 10 + remainder
        num //= 10

    return original == reversed_num  # Return true if original equals reversed

# Input from the user
num = int(input("Enter a number: "))

if is_palindrome(num):
    print("The number is a palindrome.")
else:
    print("The number is not a palindrome.")
