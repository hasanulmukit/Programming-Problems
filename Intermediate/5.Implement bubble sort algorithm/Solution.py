# Bubble Sort function
def bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap arr[j] and arr[j + 1]
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Input from the user
n = int(input("Enter the number of elements: "))
arr = []

print("Enter the elements:")
for _ in range(n):
    arr.append(int(input()))

bubble_sort(arr)

print("Sorted array:", " ".join(map(str, arr)))
