public class Main {
    public static void main(String[] args) {
        int a[] = new int[10]; // Array with extra space for insertion

        // Initializing first 6 elements
        a[0] = 4;
        a[1] = 3;
        a[2] = 5;
        a[3] = 88;
        a[4] = 6;
        a[5] = 9;

        int n = 6; // Number of valid elements in array

        // Printing original array
        System.out.println("Original Array:");
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println("\n");

        int x = 28; // Element to insert
        int index = 2; // Position to insert at

        // Shifting elements to the right
        for (int i = n; i > index; i--) {
            a[i] = a[i - 1];
        }

        a[index] = x;  // Insert new element
        n++;  // Update element count

        // Printing modified array
        System.out.println("Array after insertion:");
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
}
