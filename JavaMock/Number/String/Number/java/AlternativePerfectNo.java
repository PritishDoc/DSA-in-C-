import java.util.Scanner;

public class AlternativePerfectNo {
    public static boolean isPerfectNumber(int n) {
        if (n <= 1) return false; // Perfect numbers are greater than 1
        
        int sum = 1; // 1 is always a divisor
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) { // Add the corresponding divisor
                    sum += n / i;
                }
            }
        }
        return sum == n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a Starting and Ending number: ");
        int start = sc.nextInt();
        int end = sc.nextInt();
        sc.close();

        int count = 1; // To track alternative perfect numbers

        for (int i = start; i <= end; i++) {
            if (isPerfectNumber(i)) {
                if (count % 2 == 1) { // Print only alternate perfect numbers
                    System.out.println(i + " is a Perfect Number.");
                }
                count++; // Increment count when a perfect number is found
            }
        }
    }
}
