import java.util.Scanner;

public class Pattern {
    public static void printPattern(int n) {
        int num = 1;
        for(int i = 1; i <= n; i++) {
            // Print leading spaces
            for(int space = 1; space <= n - i; space++) {
                System.out.print("   ");
            }
            
            // Print numbers
            if(i % 2 == 1) {  // Odd rows: left to right
                for(int j = 1; j <= n; j++) {
                    System.out.printf("%2d ", num++);
                }
            } else {  // Even rows: right to left
                int temp = num + n - 1;
                for(int j = 1; j <= n; j++) {
                    System.out.printf("%2d ", temp--);
                }
                num += n;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        int n = sc.nextInt();
        printPattern(n);
        sc.close();
    }
}