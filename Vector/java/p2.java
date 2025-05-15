public class p2 {
    public static void main(String[] args) {
     //reverse num
    //automorphic

    int n=55;
    int sq=n*n;
    boolean flag =true;
    if(sq%10!=n%10)
    {
        flag=false;
    }
    sq/=10;
    n/=10;
        if(flag){
       System.out.println("yes"); 
     }  else{
        System.out.println("not");
     }
    }
      
    }

