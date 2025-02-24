package PatternProblem;

public class DiamondPattern {
    public static void main(String[] args) {
        int row=5;
        for(int i=0;i<row;i++){
            for(int j=0;j<row-i-1;j++){
                System.out.print(" ");
            }
            for(int j=0;j<=i;j++){
                System.out.print("* ");
            }
            System.out.println();
        }
        for(int i=0;i<row-1;i++){
            for(int j=0;j<=i;j++){
                System.out.print(" ");
            }
            for(int j=0;j<row-i-1;j++){
                System.out.print("* ");
            }
            System.out.println();
        }
        
    }
    
}
