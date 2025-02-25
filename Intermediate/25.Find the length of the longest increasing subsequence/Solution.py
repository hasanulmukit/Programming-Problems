def longest_increasing_subsequence(arr):
    n = len(arr)
    lis = [1] * n

    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1

    return max(lis)

if __name__ == "__main__":
    n = int(input("Enter the number of elements: "))
    arr = list(map(int, input("Enter the elements of the array: ").split()))

    result = longest_increasing_subsequence(arr)
    print("Length of Longest Increasing Subsequence:", result)
