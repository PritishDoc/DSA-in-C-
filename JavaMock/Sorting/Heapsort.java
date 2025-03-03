public class Heapsort {
    // Function to perform heap sort
    public void heapSort(int arr[]) {
        int n = arr.length;

        // Step 1: Build Max Heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Step 2: Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            // Swap root (largest) with last element
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Heapify the reduced heap
            heapify(arr, i, 0);
        }
    }

    // Function to heapify a subtree rooted at node i
    private void heapify(int arr[], int n, int i) {
        int largest = i; // Assume root is largest
        int left = 2 * i + 1; // Left child
        int right = 2 * i + 2; // Right child

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            // Recursively heapify the affected subtree
            heapify(arr, n, largest);
        }
    }

    // Function to print the array
    private void printArray(int arr[]) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    // Main function to test Heap Sort
    public static void main(String[] args) {
        Heapsort sorter = new Heapsort();
        int arr[] = {12, 11, 13, 5, 6, 7};

        System.out.println("Original array:");
        sorter.printArray(arr);

        sorter.heapSort(arr);

        System.out.println("Sorted array:");
        sorter.printArray(arr);
    }
}
