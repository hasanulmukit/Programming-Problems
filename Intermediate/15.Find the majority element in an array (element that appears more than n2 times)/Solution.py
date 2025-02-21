def find_majority_element(arr):
    count = 0
    candidate = -1

    # Finding candidate
    for num in arr:
        if count == 0:
            candidate = num
            count = 1
        elif num == candidate:
            count += 1
        else:
            count -= 1

    # Verifying candidate
    count = 0
    for num in arr:
        if num == candidate:
            count += 1

    return candidate if count > len(arr) // 2 else -1

if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    arr = list(map(int, input(f"Enter {n} elements of the array: ").split()))

    result = find_majority_element(arr)
    if result != -1:
        print(f"The majority element is: {result}")
    else:
        print("No majority element found.")
