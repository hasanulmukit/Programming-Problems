def find_missing_number(arr, n):
    total = (n + 1) * (n + 2) // 2  # Sum of 1 to n+1
    return total - sum(arr)         # Subtract array elements from total

if __name__ == "__main__":
    n = int(input("Enter the size of the array (n): "))
    arr = list(map(int, input(f"Enter {n} elements of the array: ").split()))

    missing_number = find_missing_number(arr, n)
    print(f"The missing number is: {missing_number}")
