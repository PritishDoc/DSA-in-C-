import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    
	    Scanner sc=new Scanner(System.in);
	System.out.println("Enter your age to know that you are your or not young: ");
	     
	     int age=sc.nextInt();
	     
	     if(age>=18){
	         System.out.println("You are adult ");
	         
	     }
	     else{
	         System.out.println("You are younger");
	     }

	
	}
}