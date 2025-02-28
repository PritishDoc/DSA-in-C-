package PatternProblem;

public class Pyramid {
    public static void main(String[] args) {
        int n = 5; // Number of rows
        int sp = n - 1; // Initial spaces
        int st = 1; // Initial stars

        for (int i = 1; i <= n; i++) {
            // Print spaces
            for (int j = 1; j <= sp; j++) {
                System.out.print(" ");
            }
            
            // Print stars
            for (int j = 1; j <= st; j++) {
                System.out.print("*");
            }
            
            // Move to next line
            System.out.println();
            
            // Decrease spaces and increase stars
            sp--;
            st += 2;
        }
    }
}
