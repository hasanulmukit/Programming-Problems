def find_lcs(str1, str2):
    len1, len2 = len(str1), len(str2)
    dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]

    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    index = dp[len1][len2]
    lcs = [''] * index

    i, j = len1, len2
    while i > 0 and j > 0:
        if str1[i - 1] == str2[j - 1]:
            index -= 1
            lcs[index] = str1[i - 1]
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1

    print("Longest Common Subsequence:", ''.join(lcs))

if __name__ == "__main__":
    str1 = input("Enter first string: ")
    str2 = input("Enter second string: ")

    find_lcs(str1, str2)
