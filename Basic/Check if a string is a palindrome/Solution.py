# Function to check if a string is a palindrome
def is_palindrome(string):
    start, end = 0, len(string) - 1

    while start < end:
        if string[start] != string[end]:
            return False  # Not a palindrome
        start += 1
        end -= 1

    return True  # Palindrome

# Input from the user
string = input("Enter a string: ")

if is_palindrome(string):
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")
