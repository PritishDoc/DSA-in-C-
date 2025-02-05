import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    
        System.out.println(); // Newline for formatting
        int count=0;
        for(int i=1;i<=5;i++){
            for(int j=1;j<=5;j++){
               // count++;
               if(i<=j){
                System.out.print("* ");
               }
               else{
                   System.out.print(" ");
               }
        }
        System.out.println("");
    }
}}
