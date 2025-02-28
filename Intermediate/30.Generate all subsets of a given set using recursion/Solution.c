#include <stdio.h>
#include <math.h>

void generateSubsets(char *set, char *subset, int index, int n) {
    if (index == n) {
        printf("{");
        for (int i = 0; subset[i] != '\0'; i++)
            printf("%c", subset[i]);
        printf("}\n");
        return;
    }
    
    // Exclude the current element
    generateSubsets(set, subset, index + 1, n);

    // Include the current element
    int len = 0;
    while (subset[len] != '\0') len++;
    subset[len] = set[index];
    subset[len + 1] = '\0';

    generateSubsets(set, subset, index + 1, n);

    // Backtrack
    subset[len] = '\0';
}

int main() {
    int n;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    char set[n], subset[n + 1];
    subset[0] = '\0'; // Empty subset
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &set[i]);
    }

    printf("The subsets are:\n");
    generateSubsets(set, subset, 0, n);
    return 0;
}
