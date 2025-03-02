def main():
    n1 = int(input("Enter the number of elements in the first sorted array: "))
    arr1 = list(map(int, input("Enter the elements of the first sorted array (space-separated): ").split()))
    
    n2 = int(input("Enter the number of elements in the second sorted array: "))
    arr2 = list(map(int, input("Enter the elements of the second sorted array (space-separated): ").split()))
    
    i, j = 0, 0
    intersection = []
    
    while i < n1 and j < n2:
        if arr1[i] < arr2[j]:
            i += 1
        elif arr1[i] > arr2[j]:
            j += 1
        else:
            intersection.append(arr1[i])
            i += 1
            j += 1

    if intersection:
        print("Intersection of the two arrays:", " ".join(map(str, intersection)))
    else:
        print("No common elements found.")

if __name__ == "__main__":
    main()
