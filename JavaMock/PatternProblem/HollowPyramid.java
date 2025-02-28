package PatternProblem;

public class HollowPyramid {
    


    public static void main(String[] args) {
        int n = 5; // Number of rows

        for (int i = 1; i <= n; i++) {
            // Print leading spaces
            for (int j = 1; j <= n - i; j++) {
                System.out.print(" ");
            }

            // Print stars and spaces for hollow effect
            for (int j = 1; j <= 2 * i - 1; j++) {
                // Print '*' for first and last position in each row or the last row fully
                if (j == 1 || j == 2 * i - 1 || i == n) {
                    System.out.print("*");
                } else {
                    System.out.print(" ");
                }
            }

            // Move to the next line
            System.out.println();
        }
    }
}

    

