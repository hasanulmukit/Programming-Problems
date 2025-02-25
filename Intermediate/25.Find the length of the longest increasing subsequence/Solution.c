#include <stdio.h>

int longestIncreasingSubsequence(int arr[], int n) {
    int lis[n];
    for (int i = 0; i < n; i++)
        lis[i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    int max = 0;
    for (int i = 0; i < n; i++)
        if (lis[i] > max)
            max = lis[i];

    return max;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = longestIncreasingSubsequence(arr, n);
    printf("Length of Longest Increasing Subsequence: %d\n", result);

    return 0;
}
