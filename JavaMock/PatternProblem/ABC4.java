package PatternProblem;

public class ABC4 {
    public static void main(String[] args) {
        int n=5;
        for(int i=1;i<=n;i++){
            char c='A';
            for(int j=1;j<=n;j++){
                System.out.print(j);
                if(i>2&&j==1&&i+j>=3&&i+j<=5){
                    System.out.print(c);
                }
                c++;
            }
            System.out.println();
        }
    }
    
}
