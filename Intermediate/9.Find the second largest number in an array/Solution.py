def find_second_largest(arr):
    if len(arr) < 2:
        print("Error: Array must have at least two elements.")
        return

    largest = second_largest = float('-inf')

    for num in arr:
        if num > largest:
            second_largest = largest
            largest = num
        elif num > second_largest and num != largest:
            second_largest = num

    if second_largest == float('-inf'):
        print("There is no second largest element.")
    else:
        print("The second largest number is:", second_largest)

if __name__ == "__main__":
    n = int(input("Enter the number of elements: "))
    if n < 2:
        print("Error: Array must have at least two elements.")
    else:
        arr = []
        print("Enter the elements of the array: ")
        for _ in range(n):
            arr.append(int(input()))
        find_second_largest(arr)
