#include <stdio.h>

void findDuplicates(int arr[], int n) {
    printf("Duplicate elements: ");
    int found = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                found = 1;
                break; // Avoid printing the same duplicate multiple times
            }
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findDuplicates(arr, n);

    return 0;
}
