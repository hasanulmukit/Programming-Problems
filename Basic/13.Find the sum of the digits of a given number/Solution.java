import java.util.Scanner;

public class SumOfDigits {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = scanner.nextInt();
        int sum = 0;

        while (num != 0) {
            sum += num % 10; // Get the last digit
            num /= 10;       // Remove the last digit
        }

        System.out.println("Sum of the digits: " + sum);
    }
}
