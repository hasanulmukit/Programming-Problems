#include <stdio.h>

void moveZerosToEnd(int arr[], int n) {
    int j = 0; // Points to the next position for a non-zero element

    // Traverse the array
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            // Swap non-zero element with the element at index j
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements of the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    moveZerosToEnd(arr, n);

    printf("Array after moving zeros to the end: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
