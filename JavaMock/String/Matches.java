package String;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Matches {
    public static void main(String[] args) {
        System.out.println("Enter a 3-digit number: ");
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        // Correct regex pattern for a 3-digit number
        Pattern p = Pattern.compile("\\d{3}");
        Matcher m = p.matcher(s);

        if (m.matches()) {
            System.out.println("Valid");
        } else {
            System.out.println("Invalid");
        }

        sc.close(); // Close the scanner to prevent resource leaks
    }
}
