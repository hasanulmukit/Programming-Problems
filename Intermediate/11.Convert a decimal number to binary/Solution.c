#include <stdio.h>

void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    int binary[32];
    int index = 0;

    while (n > 0) {
        binary[index++] = n % 2;
        n /= 2;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("Binary representation: ");
    decimalToBinary(num);
    printf("\n");

    return 0;
}
