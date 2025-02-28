package PatternProblem;

public class ab3 {
    public static void main(String[] args) {
        int n=6;
        for(int i=1;i<=n;i++){
            char c='A';
            for(int j=1;j<=n;j++){
                if((i+j)%2==0){
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
