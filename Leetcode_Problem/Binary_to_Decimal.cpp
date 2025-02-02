import java.util.*;
public class Main
{
	public static void main(String[] args) {
		System.out.println("Hello World");
		Scanner sc=new Scanner(System.in);
		
        System.out.println("Enter the binary num: ");
        String num=sc.nextLine();
        
        if(!num.matches("[01]+")){
            System.out.println("The num is not a binary");
        }
        else{
            int decimalValue=Integer.parseInt(num,2);
            System.out.println("The decimal num is : "+decimalValue);
        }
	}
}
