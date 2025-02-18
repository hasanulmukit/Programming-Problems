def count_vowels_and_consonants(string):
    vowels = 0
    consonants = 0

    for ch in string.lower():
        if ch.isalpha():
            if ch in 'aeiou':
                vowels += 1
            else:
                consonants += 1

    return vowels, consonants


if __name__ == "__main__":
    string = input("Enter a string: ")
    vowels, consonants = count_vowels_and_consonants(string)
    print(f"Vowels: {vowels}")
    print(f"Consonants: {consonants}")
