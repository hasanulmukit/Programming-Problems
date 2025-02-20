#include <stdio.h>

void findPairs(int arr[], int n, int target) {
    int found = 0;
    printf("Pairs with sum %d:\n", target);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("No pairs found.\n");
    }
}

int main() {
    int n, target;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements of the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    findPairs(arr, n, target);

    return 0;
}
