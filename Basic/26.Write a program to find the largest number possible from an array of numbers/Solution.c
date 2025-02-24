#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom comparator function for sorting
int compare(const void *a, const void *b) {
    char x[20], y[20];
    sprintf(x, "%s%s", (char *)a, (char *)b);
    sprintf(y, "%s%s", (char *)b, (char *)a);
    return strcmp(y, x); // Sort in descending order
}

// Function to find the largest number
void findLargestNumber(char arr[][20], int n) {
    qsort(arr, n, sizeof(arr[0]), compare);

    printf("Largest number: ");
    for (int i = 0; i < n; i++) {
        printf("%s", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    char arr[n][20];
    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    findLargestNumber(arr, n);
    return 0;
}
