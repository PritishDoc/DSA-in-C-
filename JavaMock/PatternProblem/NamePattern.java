package PatternProblem;

public class NamePattern {
    public static void main(String[] args) {
        int n=5;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==1|| j==1||i==3||(j==n && i+j<=8)){
                    System.out.print("*");
                }
                else{
                    System.out.print(" ");
                }

                } 
                System.out.println();
            }
        }
        
    }
    

