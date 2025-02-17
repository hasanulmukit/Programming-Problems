#include <stdio.h>
#include <string.h>

int main() {
    char str[100], rev[100];
    int len, i, j;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);
    if (str[len - 1] == '\n') str[--len] = '\0';  // Remove newline character

    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        rev[j] = str[i];
    }
    rev[j] = '\0';

    printf("Reversed string: %s\n", rev);

    return 0;
}
