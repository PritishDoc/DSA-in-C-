import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking input
        System.out.print("Enter two numbers to perform the operation: ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.nextLine(); // Consume the leftover newline to avoid input issues

        // Taking operation as input
        System.out.print("Enter the operation (add, sub, division, mul): ");
        String op = sc.nextLine();

        // Performing operation based on user input
        switch (op.toLowerCase()) {  // Converting to lowercase for case-insensitivity
            case "add":
                System.out.println("Result: " + (a + b));
                break;
            case "sub":
                System.out.println("Result: " + (a - b));
                break;
            case "division":
                if (b == 0) {
                    System.out.println("Error: Division by zero is not allowed.");
                } else {
                    System.out.println("Result: " + (a / b));
                }
                break;
            case "mul":
                System.out.println("Result: " + (a * b));
                break;
            default:
                System.out.println("Invalid operation! Please enter add, sub, division, or mul.");
        }

        sc.close(); // Closing scanner
    }
}
