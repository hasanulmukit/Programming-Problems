def is_unique(s):
    seen = set()
    for char in s:
        if char in seen:
            return False
        seen.add(char)
    return True

if __name__ == "__main__":
    s = input("Enter a string: ")
    if is_unique(s):
        print("The string contains all unique characters.")
    else:
        print("The string does not contain all unique characters.")
