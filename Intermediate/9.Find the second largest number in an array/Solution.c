#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, largest, secondLargest;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n < 2) {
        printf("Error: Array must have at least two elements.\n");
        return 1;
    }

    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = secondLargest = INT_MIN;
    
    for (i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN) {
        printf("There is no second largest element.\n");
    } else {
        printf("The second largest number is: %d\n", secondLargest);
    }

    return 0;
}
