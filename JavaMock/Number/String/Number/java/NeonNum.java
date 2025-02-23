public class NeonNum {
    public static void main(String[] args) {
        //9*9=81  8+1=9
        int n=5;
        int sq=n*n;
        int sum=0;
        while(sq>0){
            sum+=sq%10;
            sq/=10;
        }
        
     
        if(sum==n){
            System.out.println("Its an neon num");
        }
        else{
            System.out.println("Its not a neon num");
        }
    }
}
