def largest_number(nums):
    from functools import cmp_to_key

    # Custom comparator
    def compare(x, y):
        if x + y > y + x:
            return -1
        elif x + y < y + x:
            return 1
        else:
            return 0

    nums = sorted(nums, key=cmp_to_key(compare))
    return ''.join(nums)

# Input from user
n = int(input("Enter the number of elements: "))
nums = [input("Enter number: ") for _ in range(n)]

# Find and print the largest number
print("Largest number:", largest_number(nums))
