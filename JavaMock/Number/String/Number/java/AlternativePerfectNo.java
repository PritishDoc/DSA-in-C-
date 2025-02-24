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
        System.out.print("Enter a number to check: ");
        int num = sc.nextInt();
        sc.close();

        if (isPerfectNumber(num)) {
            System.out.println(num + " is a Perfect Number.");
        } else {
            System.out.println(num + " is NOT a Perfect Number.");
        }
    }
}
