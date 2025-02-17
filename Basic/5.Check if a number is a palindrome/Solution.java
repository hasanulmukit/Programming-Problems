import java.util.Scanner;

public class PalindromeNumber {

    // Function to check if a number is a palindrome
    static boolean isPalindrome(int num) {
        int original = num, reversed = 0, remainder;

        while (num != 0) {
            remainder = num % 10;
            reversed = reversed * 10 + remainder;
            num /= 10;
        }

        return original == reversed; // Return true if original equals reversed
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = scanner.nextInt();

        if (isPalindrome(num)) {
            System.out.println("The number is a palindrome.");
        } else {
            System.out.println("The number is not a palindrome.");
        }

        scanner.close();
    }
}
