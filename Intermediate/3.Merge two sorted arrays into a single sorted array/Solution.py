def merge_sorted_arrays(arr1, arr2):
    merged = []
    i, j = 0, 0

    # Merge both arrays
    while i < len(arr1) and j < len(arr2):
        if arr1[i] <= arr2[j]:
            merged.append(arr1[i])
            i += 1
        else:
            merged.append(arr2[j])
            j += 1

    # Copy remaining elements of arr1
    while i < len(arr1):
        merged.append(arr1[i])
        i += 1

    # Copy remaining elements of arr2
    while j < len(arr2):
        merged.append(arr2[j])
        j += 1

    return merged

# Input from the user
n1 = int(input("Enter the number of elements in the first sorted array: "))
arr1 = list(map(int, input("Enter the elements of the first sorted array: ").split()))

n2 = int(input("Enter the number of elements in the second sorted array: "))
arr2 = list(map(int, input("Enter the elements of the second sorted array: ").split()))

merged = merge_sorted_arrays(arr1, arr2)

print("Merged sorted array:", merged)
