package String;

import java.util.Scanner;

public class LetterFrequencyString {
    public static String countLetters(String str) {
        String result="";
        int length=str.length();
        
        for(int i=0;i<length;i++){
            char currentletter=str.charAt(i);
            int count=1;
            while(i+1<length && str.charAt(i+1)==currentletter){
                count++;
                i++;
            }
            result +=currentletter;
            if(count>1){
                result+=count;
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

