/*
public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid is a peak
            if ((mid == 0 || arr[mid] > arr[mid - 1]) &&
                (mid == n - 1 || arr[mid] > arr[mid + 1])) {
                return mid;
            }

            // If the right neighbor is greater, move to the right half
            if (mid < n - 1 && arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            } else { // Otherwise, move to the left half
                high = mid - 1;
            }
        }

        return -1; // This should never happen due to problem constraints
    }
};

*/