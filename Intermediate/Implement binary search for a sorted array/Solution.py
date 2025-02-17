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

    return -1  # Target not found

# Input from the user
n = int(input("Enter the number of elements: "))
print("Enter the sorted elements:")
arr = [int(input()) for _ in range(n)]

target = int(input("Enter the target element: "))

# Perform binary search
result = binary_search(arr, target)

# Output the result
if result != -1:
    print(f"Element found at index {result}.")
else:
    print("Element not found.")
