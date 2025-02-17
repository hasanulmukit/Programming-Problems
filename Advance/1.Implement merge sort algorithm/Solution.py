def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    L = arr[left : mid + 1]
    R = arr[mid + 1 : right + 1]

    i = j = 0
    k = left

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1


def merge_sort(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2

        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)

        merge(arr, left, mid, right)


if __name__ == "__main__":
    n = int(input("Enter the number of elements: "))
    arr = list(map(int, input("Enter the elements: ").split()))

    merge_sort(arr, 0, n - 1)

    print("Sorted array:", *arr)
