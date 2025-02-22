#include <stdio.h>
#include <string.h>

void reverseWords(char str[]) {
    int start = 0, end = 0, n = strlen(str);
    char result[1000] = "";

    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == ' ' || i == 0) {
            start = (i == 0) ? 0 : i + 1;
            strncat(result, &str[start], end - start + 1);
            strcat(result, " ");
            end = i - 1;
        }
    }

    printf("Reversed sentence: %s\n", result);
}

int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline

    reverseWords(str);
    return 0;
}
