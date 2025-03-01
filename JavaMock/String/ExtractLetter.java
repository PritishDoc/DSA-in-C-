package String;
import java.util.*;;
public class ExtractLetter {
    public static String ExLetter(String str){
        String result="";
        for(int i=0;i<str.length();i++){
            char currentChar =str.charAt(i);

            if(Character.isLetter(currentChar)){//if you want to print only digit then you print Charater.toDigit();
         
                result+=currentChar;
            }
        }
        return result;
    }
    //a5b7n8f9
    //op-abnf
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();

        System.out.println("After removing numeric from string: "+ExLetter(s));
    }
    
}
