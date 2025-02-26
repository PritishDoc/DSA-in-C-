import java.util.*;

public class StringManipulation {
    public static void main(String[] args) {
        String input = "Java is an oop lang";
        
        // 1. Original String
        System.out.println("1) " + input);
        
        // 2. Reverse the entire string
        String reversedString = new StringBuilder(input).reverse().toString();
        System.out.println("2) " + reversedString);
        
        // 3. Convert to lowercase
        System.out.println("3) " + input.toLowerCase());

        // 4. Reverse word order using Collections
        String[] words = input.split(" ");
        List<String> wordList = new ArrayList<>(Arrays.asList(words));
        Collections.reverse(wordList);
        System.out.println("4) " + String.join(" ", wordList));

        // 5. Reverse word order using array (Alternative)
        StringBuilder reversedWordOrder = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--) {
            reversedWordOrder.append(words[i]).append(" ");
        }
        System.out.println("5) " + reversedWordOrder.toString().trim());
    }
}
