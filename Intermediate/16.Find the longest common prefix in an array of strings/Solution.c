#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char arr[][100], int n) {
    static char prefix[100];
    strcpy(prefix, arr[0]);

    for (int i = 1; i < n; i++) {
        int j = 0;
        while (arr[i][j] && prefix[j] && arr[i][j] == prefix[j]) {
            j++;
        }
        prefix[j] = '\0'; // Terminate the prefix string
    }
    return prefix;
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char arr[n][100];
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    char* result = longestCommonPrefix(arr, n);

    if (strlen(result) > 0) {
        printf("Longest Common Prefix: %s\n", result);
    } else {
        printf("No common prefix.\n");
    }

    return 0;
}
