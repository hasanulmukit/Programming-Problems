import java.util.Scanner;

public class UniqueCharacters {
    public static boolean isUnique(String str) {
        boolean[] charSet = new boolean[256];
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (charSet[c]) {
                return false;
            }
            charSet[c] = true;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = scanner.nextLine();

        if (isUnique(str)) {
            System.out.println("The string contains all unique characters.");
        } else {
            System.out.println("The string does not contain all unique characters.");
        }
    }
}
