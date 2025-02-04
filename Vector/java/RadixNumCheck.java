import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    
	    Scanner sc=new Scanner(System.in);
	System.out.println("Enter your num:  ");
	String num=sc.nextLine();
	if(num.matches("[01]+")){
	    System.out.println("Its a binary num");
	}
	else if(num.matches("[0-7]+")){
	    System.out.println("Octal radix=8");
	}
	else if(num.matches("[0-9A-F]+")){
	    System.out.println("Its a hexa radix");
	}
	     else{
	         System.out.println("Enter a valid num");
	     }
            
	

	
	}
}