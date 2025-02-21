#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(char str[]) {
    int count[256] = {0};
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        count[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }
    return '\0';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    char result = firstNonRepeatingChar(str);
    if (result != '\0') {
        printf("The first non-repeating character is: %c\n", result);
    } else {
        printf("No non-repeating character found.\n");
    }

    return 0;
}
