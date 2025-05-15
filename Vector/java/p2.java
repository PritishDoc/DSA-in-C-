public class p2 {
    public static void main(String[] args) {
     //reverse num
    //automorphic
    //neon num
    int n=9;
    int sq=n*n;
    int sum=0;
    while(sq>0){
        int num=sq%10;
        sum=sum+num;
        n/=10;
    }
    if(sum==n){
        System.out.println("automorphic");
    }
    else{
        System.out.println("not");
    }
    }
      
    }

