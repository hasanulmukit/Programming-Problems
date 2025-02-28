def generate_subsets(s, index, current_subset):
    # Base case: if we've processed all elements, print the current subset.
    if index == len(s):
        print("{", " ".join(map(str, current_subset)), "}")
        return
    
    # Recurse without including the current element.
    generate_subsets(s, index + 1, current_subset)
    
    # Include the current element.
    current_subset.append(s[index])
    generate_subsets(s, index + 1, current_subset)
    
    # Backtrack: remove the last element before returning.
    current_subset.pop()

if __name__ == "__main__":
    n = int(input("Enter the number of elements in the set: "))
    s = []
    print("Enter the elements:")
    for _ in range(n):
        # Change int(input()) to input() if you want to work with strings.
        s.append(int(input()))
    
    print("\nAll subsets:")
    generate_subsets(s, 0, [])
