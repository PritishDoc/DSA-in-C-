public class p2 {
    public static void main(String[] args) {
     //reverse num
        int n=2345;
        int rev=0;
        while(n>0){
            int rem=n%10;
            rev=rev*10+rem;
            n/=10;
        }
       System.out.println(rev); 
     }  
      
    }

