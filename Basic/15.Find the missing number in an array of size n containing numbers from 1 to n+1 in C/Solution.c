#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2; // Sum of 1 to n+1
    for (int i = 0; i < n; i++) {
        total -= arr[i]; // Subtract array elements from total
    }
    return total;
}

int main() {
    int n;
    printf("Enter the size of the array (n): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements of the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int missingNumber = findMissingNumber(arr, n);
    printf("The missing number is: %d\n", missingNumber);

    return 0;
}
