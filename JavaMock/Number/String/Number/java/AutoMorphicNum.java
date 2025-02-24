public class AutoMorphicNum {
    public static void main(String[] args) {
        int n=3;
        int sq=n*n;
        boolean flag=true;
        while(n>0){
            if(n%10 !=sq%10){
                flag=false;
                break;
            }
                //System.out.println("Not a automorphic num");
                n/=10;
            sq/=10;
            
            //POW OF 5 =25 THEN 5 ISIN LAST DIGIT
        }
        if(flag){
            System.out.println("Its a automorphic num");
        }
        else{
            System.out.println("Its not an automorphic num");
        }
    }
    
}
