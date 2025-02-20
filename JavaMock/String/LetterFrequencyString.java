package String;

import java.util.Scanner;

public class LetterFrequencyString {
    public static String countLetters(String str) {
        String result = "";
        int len = str.length();

        for (int i = 0; i < len; i++) {
            char currentChar = str.charAt(i);
            int count = 1;

            // Count consecutive occurrences of currentChar
            while (i + 1 < len && str.charAt(i + 1) == currentChar) {
                count++;
                i++; // Move to the next occurrence
            }

            result += currentChar; // Add character to result
            if (count > 1) {
                result += count; // Add count if more than 1
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = sc.nextLine();
        sc.close();

        String output = countLetters(input);
        System.out.println("Compressed Output: " + output);
    }
}

