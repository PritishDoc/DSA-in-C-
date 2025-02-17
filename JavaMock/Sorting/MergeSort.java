public class MergeSort {
    static void devide(int arr[], int si, int ei) {
        if (si >= ei) return; // Base case to stop recursion

        int mid = si + (ei - si) / 2;
        devide(arr, si, mid);
        devide(arr, mid + 1, ei);

        conqure(arr, si, ei, mid);
    }

    static void conqure(int arr[], int si, int ei, int mid) {
        int merged[] = new int[ei - si + 1];
        int indx1 = si;
        int indx2 = mid + 1;  // Fixed initialization
        int x = 0;

        while (indx1 <= mid && indx2 <= ei) {
            if (arr[indx1] <= arr[indx2]) {
                merged[x++] = arr[indx1++];
            } else {
                merged[x++] = arr[indx2++];
            }
        }

        while (indx1 <= mid) {
            merged[x++] = arr[indx1++];
        }

        while (indx2 <= ei) {
            merged[x++] = arr[indx2++];
        }

        // Corrected loop condition
        for (int i = 0, j = si; i < merged.length; i++, j++) {
            arr[j] = merged[i];
        }
    }

    public static void main(String[] args) {
        int arr[] = {3, 9, 8, 2, 1};
        int n = arr.length - 1;

        devide(arr, 0, n);

        for (int x : arr) {
            System.out.print(x + " ");  // Corrected print statement
        }
        System.out.println();
    }
}
