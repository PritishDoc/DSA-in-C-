#include<iostream>
#include<algorithm> // for sort
using namespace std;

int main(){
    int n = 5;
    int arr[5] = {1, 1, 2, 2, 2};

    // Sort the array
    sort(arr, arr + n);

    // Frequency count
    int freq = 1, maxFreq = 1, ans = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            freq++;
        } else {
            freq = 1; // reset frequency count
        }
        if (freq > maxFreq) { // update the answer if higher frequency is found
            maxFreq = freq;
            ans = arr[i];
        }
    }
    
    cout << "Most frequent element is: " << ans << endl;
    
    return 0;
}
