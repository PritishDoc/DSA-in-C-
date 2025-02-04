import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    
	    Scanner sc=new Scanner(System.in);
		
		int a=5,b=88,c=22;
		
		if(a>b && a>c){
		    System.out.println("A is greater: ");
		}
		else{
		    if(b>c){
		        System.out.println("B is greater");
		    }
		    else{
		        System.out.println("C is greater");
		    }
		}
	
	}
}
