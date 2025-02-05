import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    Scanner sc=new Scanner(System.in);
		System.out.println("Enter a num : ");
		
		int r;
		int reversenum=0;
		int num=sc.nextInt();
		while(num>0){
		     r=num%10;
		     reversenum=reversenum*10+r;
		    num=num/10;
		    
		}
		System.out.println(reversenum);
	}
}