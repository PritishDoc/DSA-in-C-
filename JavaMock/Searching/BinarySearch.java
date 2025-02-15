public class BinarySearch {
    static int bb(int arr[], int key) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (key > arr[mid]) {
                start = mid + 1;
            } else if (key < arr[mid]) {
                end = mid - 1;
            } else {
                return mid; // Found the key, return its index
            }
        }
        return -1; // Key not found
    }

    public static void main(String[] args) {
        int arr[] = {1, 2, 4, 5, 6, 7, 24};
        int key = 7;
        int result = bb(arr, key);
        if (result != -1) {
            System.out.println("Element found at index: " + result);
        } else {
            System.out.println("Element not found");
        }
    }
}
