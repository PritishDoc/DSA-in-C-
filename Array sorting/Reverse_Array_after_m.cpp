#include <iostream>
#include <vector>
using namespace std;

// Function to reverse a vector in place
void reverse(vector<int>& v,int m) {
    int start = m+1;
    int end = v.size() - 1;
    while (start < end) {
        swap(v[start++], v[end--]);
    }
}

// Function to print elements of the vector
void print(const vector<int>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;
    v.push_back(11);
    v.push_back(4);
    v.push_back(9);
    v.push_back(5);
    v.push_back(55);
    v.push_back(6);
    int m=2;
    reverse(v,m);  // Reverse the vector in place
    print(v);    // Print the reversed vector
    return 0;
}
