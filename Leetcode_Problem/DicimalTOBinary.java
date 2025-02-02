import java.util.scanner;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a decimal number: ");
        if (sc.hasNextInt()) {  // Check if the input is a valid integer
            int decimalNum = sc.nextInt();

            // Convert to binary using an optimized built-in function
            String binaryStr = Integer.toBinaryString(decimalNum);

            System.out.println("Binary representation: " + binaryStr);
        } else {
            System.out.println("Invalid input! Please enter an integer.");
        }

        sc.close(); // Close scanner to prevent memory leaks
    }
}
