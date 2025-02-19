package String;

import java.util.Scanner;

public class Palindrome {
    static boolean isPalindrome(String s1) {
        int i = 0, j = s1.length() - 1;

        while (i < j) {
            if (s1.charAt(i) != s1.charAt(j)) {
                return false; // If mismatch, not a palindrome
            }
            i++;
            j--;
        }
        return true; // If no mismatches, it's a palindrome
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a String: ");
        String s1 = sc.nextLine();
        
        if (isPalindrome(s1)) {
            System.out.println("The string is a palindrome.");
        } else {
            System.out.println("The string is NOT a palindrome.");
        }
        
        sc.close(); // Close Scanner to avoid resource leak
    }
}
