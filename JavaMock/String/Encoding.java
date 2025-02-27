import java.util.Scanner;
public class Encoding {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter a String: ");
        String str=sc.nextLine();
        System.out.println("Enter Encoding Leve: ");
        int n=sc.nextInt();
        char[] alpha="abcdefghijklmnopqrstuvwxyz".toCharArray();
        char[] arr=str.toCharArray();
        
        for(int i=0;i<arr.length;i++){
            char c=arr[i];
            int index=c-97;
            index=(index+c)%26;
            System.out.println(index);
            arr[i]=alpha[index];
            String s2=new String(arr);
            System.out.println(s2);
        }
    }
    
}
