def reverse_words(sentence):
    words = sentence.split()
    return ' '.join(reversed(words))

if __name__ == "__main__":
    sentence = input("Enter a sentence: ")
    result = reverse_words(sentence)
    print("Reversed sentence:", result)
