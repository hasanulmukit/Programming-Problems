def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

if __name__ == "__main__":
    n = int(input("Enter the number of elements: "))
    arr = list(map(int, input("Enter the elements: ").split()))

    insertion_sort(arr)

    print("Sorted array:", *arr)
