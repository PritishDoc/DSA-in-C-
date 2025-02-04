import java.util.Scanner;
public class Main
{
	public static void main(String[] args) {
	    
	    Scanner sc=new Scanner(System.in);
        System.out.println("Enter the year to check wheather its leap year or not : ");
        
        int year=sc.nextInt();
        if(year%400==0 || (year%4==0 && year%100!=0)){
            System.out.println("Its a leap year");
        }
        else{
            System.out.println("Its not a leap year");
        }

	
	}
}
