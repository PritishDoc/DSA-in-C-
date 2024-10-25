#include<iostream>
using namespace std;

int main() {
    int size = 6;
    int arr[size] = {3, 99, 67, 4, 2, 34};
    
    // Initialize smallest and largest to extreme values
    int smallest = INT16_MAX;
    int largest = INT16_MIN;

    // Variables to store the index of the smallest and largest elements
    int smallestIndex = 0;
    int largestIndex = 0;

    // Traverse the array
    for(int i = 0; i < size; i++) {
        // Check if the current element is smaller than the current smallest
        if(arr[i] < smallest) {
            smallest = arr[i];   // Update the smallest value
            smallestIndex = i;   // Update the index of the smallest value
        }

        // Check if the current element is larger than the current largest
        if(arr[i] > largest) {
            largest = arr[i];    // Update the largest value
            largestIndex = i;    // Update the index of the largest value
        }
    }

    // Print the smallest and largest elements along with their indices
    cout << "Smallest element = " << smallest << " at index = " << smallestIndex << endl;
    cout << "Largest element = " << largest << " at index = " << largestIndex << endl;

    return 0;
}
