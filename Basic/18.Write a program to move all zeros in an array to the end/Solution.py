def move_zeros_to_end(arr):
    j = 0  # Points to the next position for a non-zero element

    # Traverse the array
    for i in range(len(arr)):
        if arr[i] != 0:
            arr[i], arr[j] = arr[j], arr[i]
            j += 1

if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    arr = list(map(int, input(f"Enter {n} elements of the array: ").split()))

    move_zeros_to_end(arr)

    print("Array after moving zeros to the end:", *arr)
