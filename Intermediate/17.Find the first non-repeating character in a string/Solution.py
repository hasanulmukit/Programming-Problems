def first_non_repeating_char(s):
    from collections import Counter
    count = Counter(s)

    for char in s:
        if count[char] == 1:
            return char
    return None

if __name__ == "__main__":
    s = input("Enter a string: ")
    result = first_non_repeating_char(s)
    if result:
        print(f"The first non-repeating character is: {result}")
    else:
        print("No non-repeating character found.")
