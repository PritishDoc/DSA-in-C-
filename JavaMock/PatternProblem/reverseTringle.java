package PatternProblem;

public class reverseTringle {
    public static void main(String[] args) {
        int n=4;
        int x=n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=x;j++){
                System.out.print(j);
            }
            System.out.println();
        }
        x--;
    }
    
}
