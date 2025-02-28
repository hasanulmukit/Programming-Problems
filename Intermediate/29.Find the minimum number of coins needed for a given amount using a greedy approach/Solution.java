import java.util.Scanner;

public class CoinChange {
    // Function to find the minimum number of coins
    public static void findMinCoins(int[] coins, int amount) {
        int count = 0;

        System.out.print("Coins used: ");
        for (int coin : coins) {
            while (amount >= coin) {
                amount -= coin;
                System.out.print(coin + " ");
                count++;
            }
        }

        if (amount > 0) {
            System.out.println("\nCannot make the exact amount with the given denominations.");
        } else {
            System.out.println("\nMinimum number of coins needed: " + count);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number of coin denominations
        System.out.print("Enter the number of coin denominations: ");
        int n = scanner.nextInt();

        int[] coins = new int[n];
        System.out.println("Enter the coin denominations in descending order: ");
        for (int i = 0; i < n; i++) {
            coins[i] = scanner.nextInt();
        }

        // Input the amount
        System.out.print("Enter the amount: ");
        int amount = scanner.nextInt();

        findMinCoins(coins, amount);
    }
}
