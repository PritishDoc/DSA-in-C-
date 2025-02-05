import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a num: ");
        int num=sc.nextInt();
        System.out.println("Enter the distance you want: ");
        int d=sc.nextInt();
        System.out.println("Enter the how many terms you want: ");
        int n=sc.nextInt();
        int term =num;
        for(int i=0;i<=n;i++){
            System.out.print(term+",");
            term+=d;
        }
        
        System.out.println(); // Newline for formatting
    }
}
