public class p2 {
    public static void main(String[] args) {
     //reverse num
    //automorphic
    //neon num
    //spy num
        int n=123;
        int sum=0;
        int mul=0;

        while(n>0){
            sum+=n%10;
            mul+=n%10;
            n/=10;

        }
      if(sum==mul){
        System.out.println("Perfectno");
      }
      else{
        System.out.println("Not perfect");
      }
    }
}

