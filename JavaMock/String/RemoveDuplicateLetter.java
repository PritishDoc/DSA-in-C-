package String;
import java.util.Scanner;
public class RemoveDuplicateLetter {
    public static String Duplicate(String str){
        String result="";
        for(int i=0;i<str.length();i++){
            char currentChar=str.charAt(i);

            if(result.indexOf(currentChar)==-1){
                result+=currentChar;
            }
            
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        String s=sc.nextLine();
        sc.close();
        System.out.println("After removing the rpeted letter the string is : "+Duplicate(s));
    }
}
