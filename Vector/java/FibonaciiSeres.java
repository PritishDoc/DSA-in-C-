import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a num: ");
        int num=sc.nextInt();
        int a=0;
        int b=1;
        int c;
        System.out.print(a+","+b+",");
        for(int i=0;i<num-2;i++){
            c=a+b;
            System.out.print(c+",");
            a=b;
            b=c;
        }
        
        System.out.println(); // Newline for formatting
    }
}
