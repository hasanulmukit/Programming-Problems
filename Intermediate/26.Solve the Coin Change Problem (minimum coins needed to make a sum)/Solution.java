import java.util.Scanner;

public class CoinChange {
    public static int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        for (int i = 1; i <= amount; i++) {
            dp[i] = Integer.MAX_VALUE;
            for (int coin : coins) {
                if (i >= coin && dp[i - coin] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of coin types: ");
        int n = sc.nextInt();

        int[] coins = new int[n];
        System.out.println("Enter the coin denominations:");
        for (int i = 0; i < n; i++)
            coins[i] = sc.nextInt();

        System.out.print("Enter the amount: ");
        int amount = sc.nextInt();

        int result = coinChange(coins, amount);
        if (result == -1)
            System.out.println("No solution exists.");
        else
            System.out.println("Minimum coins needed: " + result);
    }
}
