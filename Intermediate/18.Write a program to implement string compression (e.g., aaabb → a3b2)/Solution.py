def compress_string(s):
    compressed = []
    count = 1

    for i in range(len(s)):
        if i < len(s) - 1 and s[i] == s[i + 1]:
            count += 1
        else:
            compressed.append(f"{s[i]}{count}")
            count = 1

    return ''.join(compressed)

if __name__ == "__main__":
    s = input("Enter a string: ")
    result = compress_string(s)
    print("Compressed string:", result)
