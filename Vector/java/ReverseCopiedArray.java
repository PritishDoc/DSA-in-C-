public class Main {
    public static void main(String[] args) {
        int a[] = new int[10]; // Destination array with extra space
        int b[] = {12, 21, 34, 54, 6, 7}; // Source array

        // Reverse copy elements from b[] to a[]
        for (int i = 0; i < b.length; i++) {
            a[i] = b[b.length - 1 - i]; // Copy elements in reverse order
        }

        // Print the reversed copied array
        System.out.print("Reversed Copied Array: ");
        for (int i = 0; i < b.length; i++) {
            System.out.print(a[i] + ", ");
        }
        for(int x:a){
            System.out.print(a);
        }
    }
}
