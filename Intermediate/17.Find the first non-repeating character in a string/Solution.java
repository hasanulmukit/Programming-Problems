import java.util.LinkedHashMap;
import java.util.Scanner;

public class FirstNonRepeatingChar {
    public static char firstNonRepeatingChar(String str) {
        LinkedHashMap<Character, Integer> count = new LinkedHashMap<>();

        for (char c : str.toCharArray()) {
            count.put(c, count.getOrDefault(c, 0) + 1);
        }

        for (char c : str.toCharArray()) {
            if (count.get(c) == 1) {
                return c;
            }
        }

        return '\0';
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = scanner.nextLine();

        char result = firstNonRepeatingChar(str);
        if (result != '\0') {
            System.out.println("The first non-repeating character is: " + result);
        } else {
            System.out.println("No non-repeating character found.");
        }
    }
}
