def find_pairs(arr, target):
    found = False
    print(f"Pairs with sum {target}:")
    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            if arr[i] + arr[j] == target:
                print(f"({arr[i]}, {arr[j]})")
                found = True
    if not found:
        print("No pairs found.")

if __name__ == "__main__":
    n = int(input("Enter the size of the array: "))
    arr = list(map(int, input(f"Enter {n} elements of the array: ").split()))

    target = int(input("Enter the target sum: "))
    find_pairs(arr, target)
