import java.util.Scanner;

public class DecimalToBinary {
    public static void decimalToBinary(int n) {
        if (n == 0) {
            System.out.print("0");
            return;
        }

        String binary = "";
        while (n > 0) {
            binary = (n % 2) + binary;
            n /= 2;
        }

        System.out.print(binary);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a decimal number: ");
        int num = scanner.nextInt();

        System.out.print("Binary representation: ");
        decimalToBinary(num);
        System.out.println();
    }
}
