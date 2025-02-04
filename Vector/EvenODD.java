import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    
	    Scanner sc=new Scanner(System.in);
	System.out.println("Enter a num to check wheater that is even or odd: ");
	int num=sc.nextInt();
	    
	    if(num%2==0){
	        System.out.println("The num is even ");
	    }
	    else{
	        System.out.println("The num is odd");
	    }
	
	}
}