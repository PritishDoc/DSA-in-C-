#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
    int ans = 0;
    for (int val : nums) {
        ans = ans ^ val;  // XOR each element individually
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 4, 5, 4, 5};
    int ans = solution(nums);
    cout << "The unique element is: " << ans << endl;
    return 0;
}
