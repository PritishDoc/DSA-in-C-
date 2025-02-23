public class AlterNativePrimeNum {
    public static boolean isPrime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
           
        }
         return true;
    }
    public static  void AlPrime(int start,int end){
        int count=0;
        System.out.println("The Prime no starting range is : "+start+" Ending range is: "+end);
        for(int i=start;i<=end;i++){
            if(isPrime(i)){
                if(count%2==0){
                    System.out.print(i+",");
                }
                count++;
            }
        }
    }
    public static void main(String[] args) {
        int start=10;
        int end=50;
        AlPrime(start,end);
    }
}
