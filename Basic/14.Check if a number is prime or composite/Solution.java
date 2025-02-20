import java.util.Scanner;

public class PrimeOrComposite {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = scanner.nextInt();
        boolean isPrime = true;

        if (num <= 1) {
            System.out.println("The number is neither prime nor composite.");
        } else {
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) {
                System.out.println("The number is prime.");
            } else {
                System.out.println("The number is composite.");
            }
        }
    }
}
