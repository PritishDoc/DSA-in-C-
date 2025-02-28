package PatternProblem;

public class hollopyramid {
    public static void main(String[] args) {
        int n=50;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==3||i+j==3||j-i==3){
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
