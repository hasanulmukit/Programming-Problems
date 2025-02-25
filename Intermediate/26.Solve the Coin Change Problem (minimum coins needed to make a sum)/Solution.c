#include <stdio.h>
#include <limits.h>

int coinChange(int coins[], int n, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                dp[i] = (dp[i] < dp[i - coins[j]] + 1) ? dp[i] : dp[i - coins[j]] + 1;
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;
    printf("Enter the number of coin types: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter the coin denominations:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("Enter the amount: ");
    scanf("%d", &amount);

    int result = coinChange(coins, n, amount);
    if (result == -1)
        printf("No solution exists.\n");
    else
        printf("Minimum coins needed: %d\n", result);

    return 0;
}
