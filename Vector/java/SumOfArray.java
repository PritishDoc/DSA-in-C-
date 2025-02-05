import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    
   int arr[]=new int[5];
   
   int arr2[]={22,34,55,66};
   System.out.println(arr2.length);
   int sum=0;
    for(int i=0;i<arr2.length;i++){
        
        sum+=arr2[i];
    }
    System.out.println(sum);
}}
