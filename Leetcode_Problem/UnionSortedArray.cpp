/*

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                // If result is empty or last element is not same as a[i]
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
            } else if (a[i] > b[j]) {
                if (result.empty() || result.back() != b[j]) {
                    result.push_back(b[j]);
                }
                j++;
            } else {  // a[i] == b[j]
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
                j++;
            }
        }
        
        // Add remaining elements from a
        while (i < a.size()) {
            if (result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
        }
        
        // Add remaining elements from b
        while (j < b.size()) {
            if (result.empty() || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            j++;
        }
        
        return result;
    }
};

