public class NeonNoHighest {
    
    // Function to check if a number is Neon
    public static boolean isNeon(int n) {
        int sq = n * n;
        int sum = 0;
        
        // Sum the digits of the square
        while (sq > 0) {
            sum += sq % 10;
            sq /= 10;
        }
        
        return sum == n; // Returns true if it's a Neon number
    }

    // Function to find the highest Neon number in range
    public static void findHighestNeonInRange(int start, int end) {
        for (int i = end; i >= start; i--) { // Check from highest to lowest
            if (isNeon(i)) {
                System.out.println("Highest Neon Number in range: " + i);
                return; // Stop after finding the first (highest) Neon number
            }
        }
        System.out.println("No Neon number found in the given range.");
    }

    public static void main(String[] args) {
        int start = 15;
        int end = 25;
        findHighestNeonInRange(start, end);
    }
}
