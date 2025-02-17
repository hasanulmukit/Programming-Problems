# Input string
string = input("Enter a string: ")

# Reverse string manually
reversed_string = ""
for i in range(len(string) - 1, -1, -1):
    reversed_string += string[i]

# Output
print("Reversed string:", reversed_string)
