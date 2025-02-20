package String;
import java.util.*;
public class StringDigitCalculation {
    public static int sumDigit(String str){
        int num=0;
        int sum=0;
        for(Character ch:str.toCharArray()){
            if(Character.isDigit(ch)){
                num=num*10+(ch-'0');
            }
            else{
                sum+=num;
                num=0;
            }
        }
        return sum+=num;

    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        String input=sc.nextLine();
        sc.close();
        System.out.println("The sum of digit is : "+sumDigit(input));
    }
    
}
