import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a num: ");
        
        String n = sc.next(); // Read input as a string
        String reversenum = "";
        
        // Reverse the number manually
        for (int i = n.length() - 1; i >= 0; i--) {
            reversenum += n.charAt(i);
        }
        
        System.out.println("Reversed Number: " + reversenum);
        
        // Print each digit in words
        System.out.print("In Words: ");
        for (int i = 0; i < reversenum.length(); i++) {
            switch (reversenum.charAt(i)) {
                case '0': System.out.print("Zero "); break;
                case '1': System.out.print("One "); break;
                case '2': System.out.print("Two "); break;
                case '3': System.out.print("Three "); break;
                case '4': System.out.print("Four "); break;
                case '5': System.out.print("Five "); break;
                case '6': System.out.print("Six "); break;
                case '7': System.out.print("Seven "); break;
                case '8': System.out.print("Eight "); break;
                case '9': System.out.print("Nine "); break;
            }
        }
        System.out.println(); // Newline for formatting
    }
}
