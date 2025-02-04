import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
int sum=0;
      //reverse
      int count=0;
      int r;
      System.out.println("Enter the number: ");
      int n=sc.nextInt();
      while(n>0){
          r=n%10;
          n=n/10;
          count++;
          System.out.print(r);
      }
     System.out.print(count);
    }
}


