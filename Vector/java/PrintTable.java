import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

      //loop
      int n=sc.nextInt();
      System.out.println("Enter the num you want to multiply: ");
     for(int i=1;i<=10;i++){
         System.out.println(n+"x"+i+"="+n*i);
         
     }
    }
}