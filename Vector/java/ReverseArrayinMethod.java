import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int arr[] = {2, 4, 5, 6, 7}; // Fixed variable name
        System.out.println("The reversed array is: " + Arrays.toString(reverseArray(arr)));
    }

    static int[] reverseArray(int arr[]) {
        int n = arr.length;
        int arr2[] = new int[n]; // Fixed array initialization

        // Reversing the array
        for (int i = 0; i < n; i++) {
            arr2[i] = arr[n - 1 - i]; // Corrected indexing
        }

        return arr2; // Returning reversed array
    }
}
