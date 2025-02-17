# Function to partition the array
def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            # Swap arr[i] and arr[j]
            arr[i], arr[j] = arr[j], arr[i]

    # Swap arr[i + 1] and arr[high] (pivot)
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# QuickSort function
def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# Input from the user
n = int(input("Enter the number of elements: "))
arr = []

print("Enter the elements:")
for _ in range(n):
    arr.append(int(input()))

quick_sort(arr, 0, n - 1)

print("Sorted array:", " ".join(map(str, arr)))
