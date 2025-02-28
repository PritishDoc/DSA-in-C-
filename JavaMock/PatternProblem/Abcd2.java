package PatternProblem;

public class Abcd2 {
    public static void main(String[] args) {
        int n=5;
        

        for(int i=1;i<=n;i++){
            char c='A';            for(int j=1;j<=n;j++){
                if(i+j<=n){
                    System.out.print(j);
                }
                else{
                    System.out.print(c);
                }
                c++;

            }
            System.out.println();
            
        }
    }
    
}
