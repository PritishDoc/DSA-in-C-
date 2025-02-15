package Array;

public class RotateArrayNTimes {
    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 5, 6};  // Original Array
        int n = 1;  // Number of rotations

        // Reduce n if it's greater than array length
        n = n % arr.length;

        // Rotate the array n times
        for (int i = 0; i < n; i++) {
            int last = arr[arr.length - 1]; // Store last element

            // Shift elements to the right
            for (int j = arr.length - 1; j > 0; j--) {
                arr[j] = arr[j - 1];
            }

            // Place the last element at the first position
            arr[0] = last;
        }

        // Print rotated array
        for (int x : arr) {
            System.out.print(x + " ");
        }
    }
}
