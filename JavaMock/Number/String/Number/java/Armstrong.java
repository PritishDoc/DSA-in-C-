public class Armstrong {
    public static int count(int n) {
        int count = 0;
        while (n > 0) {
            count++;
            n /= 10;
        }
        return count;
    }

    static void am(int n) {
        int temp = n;
        int digits = count(n);
        int sum = 0;

        while (temp > 0) {
            int digit = temp % 10; // Correct way to extract the last digit
            sum += Math.pow(digit, digits); // Raise digit to power of total digits
            temp /= 10; // Reduce the number
        }

        if (sum == n) {
            System.out.println(n + " is an Armstrong Number.");
        } else {
            System.out.println(n + " is NOT an Armstrong Number.");
        }
    }

    public static void main(String[] args) {
        int n = 153; // Change the value to test different numbers
        am(n);
    }
}
