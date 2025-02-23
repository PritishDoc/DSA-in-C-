public class AutomorphicHighestRange {
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
    public static int Highst(int start,int end){
        for(int i=end;i>=start;i--){
            if(auto(i)){
                return i;
             //   break;
            }
            

        }
        return -1;
    }
    public static void main(String[] args) {
        int start=5;int end=10;
        int x=Highst(start, end);
        if(x!=-1){
            System.out.println("Is an auto morphic "+x);
        }
        else{
            System.out.println("Its not an automorphic");
        }
        }
    }

