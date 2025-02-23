public class AutoMorphicInArange {
    public static boolean auto(int n){
        Boolean flag=true;
        int sq=n*n;
        if(n%10!=sq%10){
           return flag=false;
           // break;
        }
        n/=10;
        sq/=10;
        return flag=true;
    }
    public static void main(String[] args) {
        int start=5;
        int end=10;

        for(int i=start;i<=end;i++){
            if(auto(i)){
                System.out.println("Automorphic num"+i);
            }
            else{
                System.out.println("Not a automorphic"+i);
            }
        }
    }
}
