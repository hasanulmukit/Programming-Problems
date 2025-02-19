def are_anagrams(str1, str2):
    if len(str1) != len(str2):
        return False

    return sorted(str1) == sorted(str2)

if __name__ == "__main__":
    str1 = input("Enter the first string: ")
    str2 = input("Enter the second string: ")

    if are_anagrams(str1, str2):
        print("The strings are anagrams.")
    else:
        print("The strings are not anagrams.")
