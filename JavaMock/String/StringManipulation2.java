import java.util.Scanner;

public class StringManipulation2 {
    public static void main(String[] args) {
        // Input String
        String str = "Java is a Programming Language 12345";
        
        // Step 1: Convert to Lowercase
        String lowerCaseStr = str.toLowerCase();
        System.out.println("Lowercase: " + lowerCaseStr);
        
        // Step 2: Reverse the Entire String
        String reversedStr = new StringBuilder(lowerCaseStr).reverse().toString();
        System.out.println("Reversed String: " + reversedStr);
        
        // Step 3: Reverse Only Digits in the String
        String digitReversedStr = reverseDigits(lowerCaseStr);
        System.out.println("String with Digits Reversed: " + digitReversedStr);
    }

    // Method to reverse only digits in the string
    public static String reverseDigits(String str) {
        char[] arr = str.toCharArray();
        int left = 0, right = arr.length - 1;
        
        // Find all digits and store their positions
        while (left < right) {
            if (!Character.isDigit(arr[left])) {
                left++;
            } else if (!Character.isDigit(arr[right])) {
                right--;
            } else {
                // Swap digits
                char temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
        return new String(arr);
    }
}
