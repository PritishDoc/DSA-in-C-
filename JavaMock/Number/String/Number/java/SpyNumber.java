import java.util.Scanner;

public class SpyNumber {
    public static boolean isSpyNumber(int num) {
        int sum = 0, product = 1, digit;

        while (num > 0) {
            digit = num % 10;  // Extract last digit
            sum += digit;       // Add to sum
            product *= digit;   // Multiply for product
            num /= 10;          // Remove last digit
        }

        return sum == product;  // Check if sum equals product
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        sc.close();

        if (isSpyNumber(num)) {
            System.out.println(num + " is a Spy Number.");
        } else {
            System.out.println(num + " is NOT a Spy Number.");
        }
    }
}
