def print_pattern(n):
    num = 1
    for i in range(1, n + 1):
        # Print leading spaces
        print("   " * (n - i), end="")
        
        # Print numbers
        if i % 2 == 1:  # Odd rows: left to right
            for j in range(n):
                print(f"{num:2d} ", end="")
                num += 1
        else:  # Even rows: right to left
            temp = num + n - 1
            for j in range(n):
                print(f"{temp:2d} ", end="")
                temp -= 1
            num += n
        print()

# Get input and call function
n = int(input("Enter the value of n: "))
print_pattern(n)