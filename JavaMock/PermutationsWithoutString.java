 import java.util.Arrays;

public class PermutationsWithoutString {
    public static void main(String[] args) {
        char[] arr = {'a', 'b', 'c'};  // Input as a character array
        generatePermutations(arr, 0);
    }

    public static void generatePermutations(char[] arr, int index) {
        if (index == arr.length - 1) {  // Base case: If the last element is fixed, print the permutation
            System.out.println(Arrays.toString(arr));
            return;
        }

        for (int i = index; i < arr.length; i++) {
            swap(arr, index, i);  // Swap to create a new permutation
            generatePermutations(arr, index + 1);  // Recur for the next index
            swap(arr, index, i);  // Backtrack (undo the swap)
        }
    }

    public static void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
