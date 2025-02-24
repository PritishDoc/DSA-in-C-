import java.util.*;
public class PrimeOrNot {
    public static boolean isPrime(int n){
        if(n%2==0) return false;
        else return true;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();

        if(isPrime(n)){
            System.out.println("No is Prime: "+n);
        }
        else{
            System.out.println("Num is not Prime: "+n);
        }
    }
    
}
