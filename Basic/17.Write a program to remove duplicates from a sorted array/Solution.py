def remove_duplicates(arr):
    if not arr:
        return []
    j = 0  # Index for the next unique element
    for i in range(1, len(arr)):
        if arr[i] != arr[j]:
            j += 1
            arr[j] = arr[i]
    return arr[:j + 1]

if __name__ == "__main__":
    n = int(input("Enter the size of the sorted array: "))
    arr = list(map(int, input(f"Enter {n} elements of the sorted array: ").split()))

    result = remove_duplicates(arr)
    print("Array after removing duplicates:", result)
