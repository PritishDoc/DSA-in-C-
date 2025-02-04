import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
int sum=0;
      //loop
      int r;
      System.out.println("Enter the number: ");
      int n=sc.nextInt();
      while(n>0){
          r=n%10;
          n=n/10;
          
          System.out.print(r);
      }
     
    }
}
