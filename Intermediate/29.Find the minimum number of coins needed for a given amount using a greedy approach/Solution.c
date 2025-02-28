#include <stdio.h>

// Function to find the minimum number of coins
void findMinCoins(int coins[], int n, int amount) {
    int count = 0;

    printf("Coins used: ");
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            printf("%d ", coins[i]);
            count++;
        }
    }

    if (amount > 0) {
        printf("\nCannot make the exact amount with the given denominations.");
    } else {
        printf("\nMinimum number of coins needed: %d\n", count);
    }
}

int main() {
    int n, amount;

    // Input the number of coin denominations
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter the coin denominations in descending order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // Input the amount
    printf("Enter the amount: ");
    scanf("%d", &amount);

    findMinCoins(coins, n, amount);

    return 0;
}
