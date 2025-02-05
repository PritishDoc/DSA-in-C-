import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    Scanner sc=new Scanner(System.in);
		System.out.println("Enter a num : ");
		
		String n=sc.next();
		String reversenum="";
		for(int i=n.length()-1;i>=0;i--){
		    reversenum+=n.charAt(i);
		}
		System.out.println(reversenum);
	}
}