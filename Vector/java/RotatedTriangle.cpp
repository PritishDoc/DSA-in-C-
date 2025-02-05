import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    
        System.out.println(); // Newline for formatting
        int count=0;
        for(int i=1;i<=5;i++){
            for(int j=1;j<=5-i+1;j++){
                count++;
                System.out.print("*"+" ");
    
        }
        System.out.println("");
    }
}}
