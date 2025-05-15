public class p2 {
    public static void main(String[] args) {
     //reverse num
     int a=2345;
     int rev=0;
     while(a>0){
        int rem=a%10;
        rev=rev*10+rem;
        a/=10;
    
     }  
         System.out.println(rev); 
    }
}
