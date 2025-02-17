# Input number of elements
n = int(input("Enter the number of elements: "))

# Input array elements
arr = []
print("Enter the elements:")
for _ in range(n):
    arr.append(int(input()))

# Initialize largest and smallest
largest = smallest = arr[0]

# Find largest and smallest
for num in arr[1:]:
    if num > largest:
        largest = num
    if num < smallest:
        smallest = num

# Output results
print("Largest number:", largest)
print("Smallest number:", smallest)
