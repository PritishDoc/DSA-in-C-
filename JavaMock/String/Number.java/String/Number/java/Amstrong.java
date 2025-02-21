

public class Amstrong {
    public static int count(int n){
        int count =0;
        while(n>0){
            count ++;
            n/=10;
        }
        return count;
    }
     static void am(int n){
        int temp= n;
        int digits=count(n);
        int sum=0;
        while(n>0){
            int digit=temp%10;
            sum+=Math.pow(digit,digit);



        }
        if(sum==n){
            System.out.println("Its a amstrong num");

        }
        else{
            System.out.println("Its not a amstrong num");
        }
    }
    public static void main(String[] args) {
        int n=234;
        am(n);


    }
}
