#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isUnique(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isUnique(str)) {
        printf("The string contains all unique characters.\n");
    } else {
        printf("The string does not contain all unique characters.\n");
    }

    return 0;
}
