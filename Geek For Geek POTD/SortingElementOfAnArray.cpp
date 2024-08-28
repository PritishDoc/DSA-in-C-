/*
Sorting Elements of an Array by Frequency
Difficulty: MediumAccuracy: 44.93%Submissions: 67K+Points: 4
Given an array of integers arr, sort the array according to the frequency of elements, i.e. elements that have higher frequency comes first. If the frequencies of two elements are the same, then the smaller number comes first.

Examples :

Input: arr[] = [5, 5, 4, 6, 4]
Output: [4, 4, 5, 5, 6]
Explanation: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are the same the smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6. The output is 4 4 5 5 6.
Input: arr[] = [9, 9, 9, 2, 5]
Output: [9, 9, 9, 2, 5]
Explanation: The highest frequency here is 3. Element 9 has the highest frequency So 9 9 9 comes first. Now both 2 and 5 have the same frequency. So we print smaller elements first. The output is 9 9 9 2 5.
Expected Time Complexity: O(n*logn)
Expected Space Complexity: O(n)

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i]≤ 105
*/
class Solution {
public:
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Step 1: Count frequency of each element
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        // Step 2: Create a vector of pairs (element, frequency)
        vector<pair<int, int>> freqArr;
        for (auto& it : freq) {
            freqArr.push_back(it);
        }

        // Step 3: Sort the vector of pairs by custom comparator
        sort(freqArr.begin(), freqArr.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;  // If frequencies are the same, sort by element value
            }
            return a.second > b.second;  // Sort by frequency in descending order
        });

        // Step 4: Construct the result array
        vector<int> result;
        for (auto& it : freqArr) {
            for (int i = 0; i < it.second; i++) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};