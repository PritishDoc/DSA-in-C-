public class NeonNumGivenRange {
    public static boolean NeonNum(int n){
        int sum=0;
        int sq=n*n;
        while(sq>0){
            sum+=sq%10;
            sq/=10;
        }
        return sum==n;
    }
    public static void main(String[] args) {
        int start=5;
        int end=16;
        for(int i=start;i<=end;i++){
       // int neon=NeonNum(i);

            if(NeonNum(i)){
                System.out.println("Its a neon num"+i);
            }
            else{
                System.out.println("Its not neon no."+i);
            }
        }
    }
}
