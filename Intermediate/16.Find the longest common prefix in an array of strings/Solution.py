def longest_common_prefix(strs):
    if not strs:
        return ""

    prefix = strs[0]
    for i in range(1, len(strs)):
        j = 0
        while j < len(strs[i]) and j < len(prefix) and strs[i][j] == prefix[j]:
            j += 1
        prefix = prefix[:j]

    return prefix

if __name__ == "__main__":
    n = int(input("Enter the number of strings: "))
    strs = []
    print("Enter the strings:")
    for _ in range(n):
        strs.append(input())

    result = longest_common_prefix(strs)
    if result:
        print("Longest Common Prefix:", result)
    else:
        print("No common prefix.")
