package String;
import java.util.*;
public class CountVowelOfString {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        sc.close();

        int count=0;
        System.out.println("Printing the String: ");
        for(int i=0;i<s.length();i++){
            char c=Character.toLowerCase(s.charAt(i));

            if(c=='a' || c=='e' || c=='i' || c=='o' ||c=='u'){
                System.out.println("The vowels are : "+c);
                count++;
            }
        }System.out.println("The total no of vowel are : "+count);
    
    
     
    }
    
}
