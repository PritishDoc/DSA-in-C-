#include <iostream>
#include <vector>

using namespace std;




int main() {
    vector<int> nums = {1,2,3,4,5,6};
   
   for(int st=0;st<nums.size();st++){
    for(int end=st;end<nums.size();end++){
        for(int i=st;i<=end;i++){
        cout<<nums[i];
        }
        cout<<" ";
    }
    cout<<endl;
   }
    return 0;
}
