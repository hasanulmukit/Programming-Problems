import java.util.Scanner;

public class CatalanNumber {

    public static long factorial(int n) {
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    public static long catalanNumber(int n) {
        long numerator = factorial(2 * n);
        long denominator = factorial(n + 1) * factorial(n);
        return numerator / denominator;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        int n = sc.nextInt();

        System.out.println("The " + n + "th Catalan number is: " + catalanNumber(n));
    }
}
