def find_duplicates(arr):
    print("Duplicate elements: ", end="")
    found = False

    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            if arr[i] == arr[j]:
                print(arr[i], end=" ")
                found = True
                break  # Avoid printing the same duplicate multiple times

    if not found:
        print("None")

# Input from the user
n = int(input("Enter the number of elements in the array: "))
arr = []

print("Enter the elements of the array:")
for _ in range(n):
    arr.append(int(input()))

find_duplicates(arr)
