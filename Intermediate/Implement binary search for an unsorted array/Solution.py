def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

# Input from the user
n = int(input("Enter the number of elements: "))
print("Enter the unsorted elements:")
arr = [int(input()) for _ in range(n)]

target = int(input("Enter the target element: "))

arr.sort()  # Sort the array

result = binary_search(arr, target)

if result != -1:
    print(f"Element found at index {result} (after sorting).")
else:
    print("Element not found.")
