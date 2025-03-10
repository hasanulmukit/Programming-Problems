import java.util.Stack;
import java.util.Scanner;

public class TowerOfHanoi {
    private static void moveDisk(Stack<Integer> src, Stack<Integer> dest, char s, char d) {
        int pole1Top = src.isEmpty() ? -1 : src.pop();
        int pole2Top = dest.isEmpty() ? -1 : dest.pop();

        if (pole1Top == -1) {
            src.push(pole2Top);
            System.out.println("Move disk " + pole2Top + " from " + d + " to " + s);
        } else if (pole2Top == -1) {
            dest.push(pole1Top);
            System.out.println("Move disk " + pole1Top + " from " + s + " to " + d);
        } else if (pole1Top > pole2Top) {
            src.push(pole1Top);
            src.push(pole2Top);
            System.out.println("Move disk " + pole2Top + " from " + d + " to " + s);
        } else {
            dest.push(pole2Top);
            dest.push(pole1Top);
            System.out.println("Move disk " + pole1Top + " from " + s + " to " + d);
        }
    }

    private static void hanoi(int n, Stack<Integer> src, Stack<Integer> aux, Stack<Integer> dest) {
        int moves = (1 << n) - 1;
        char s = 'S', d = 'D', a = 'A';

        if (n % 2 == 0) {
            char temp = d;
            d = a;
            a = temp;
        }

        for (int i = n; i >= 1; i--) src.push(i);

        for (int i = 1; i <= moves; i++) {
            if (i % 3 == 1)
                moveDisk(src, dest, s, d);
            else if (i % 3 == 2)
                moveDisk(src, aux, s, a);
            else if (i % 3 == 0)
                moveDisk(aux, dest, a, d);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of disks: ");
        int n = sc.nextInt();

        Stack<Integer> src = new Stack<>();
        Stack<Integer> aux = new Stack<>();
        Stack<Integer> dest = new Stack<>();

        hanoi(n, src, aux, dest);
    }
}
