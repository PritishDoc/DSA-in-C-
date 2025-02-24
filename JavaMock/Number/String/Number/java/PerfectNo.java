import java.util.Scanner;
public class PerfectNo {
    public static void main(String[] args) {
        System.out.println("Enter a num to check weather its perfect no or not : ");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int sum=0;
        for(int i=1;i<n;i++){
            if(n%i==0){
                sum+=i;
            }
        }
        if(sum==n){
            System.out.println("Its a perfect No.: "+n);
        }
        else{
            System.out.println("Its not a Perfect no: "+n);
        }
    }
}
