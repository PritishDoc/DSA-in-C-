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

        // 4. Reverse word order
        String[] words = input.split(" ");
        Collections.reverse(Arrays.asList(words));
        String reversedWords = String.join(" ", words);
        System.out.println("4) " + reversedWords);

        //using array
        String []arr=input.split(" ");
        for(int i=arr.length-1;i>=0;i--){
            System.out.println(arr[i]);
        }
    }
}
