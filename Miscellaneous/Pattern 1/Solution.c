#include <stdio.h>

void printPattern(int n) {
    int num = 1;
    for(int i = 1; i <= n; i++) {
        // Print leading spaces
        for(int space = 1; space <= n - i; space++) {
            printf("   ");
        }
        
        // Print numbers
        if(i % 2 == 1) {  // Odd rows: left to right
            for(int j = 1; j <= n; j++) {
                printf("%2d ", num++);
            }
        } else {  // Even rows: right to left
            int temp = num + n - 1;
            for(int j = 1; j <= n; j++) {
                printf("%2d ", temp--);
            }
            num += n;
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printPattern(n);
    return 0;
}