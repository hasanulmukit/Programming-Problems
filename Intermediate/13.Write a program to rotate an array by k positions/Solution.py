def rotate_array(arr, k):
    n = len(arr)
    k = k % n
    return arr[-k:] + arr[:-k]

if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    arr = list(map(int, input("Enter the elements of the array: ").split()))
    k = int(input("Enter the number of positions to rotate: "))

    rotated = rotate_array(arr, k)
    print("Rotated array:", rotated)
