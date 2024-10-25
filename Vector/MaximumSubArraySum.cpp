#include <iostream>
#include <vector>

using namespace std;




int main() {
    vector<int> nums = {1,2,3,4,5,6};
    int maxsum=INT16_MIN;
    
   for(int st=0;st<nums.size();st++){
    int curentsum=0;
    for(int end=st;end<nums.size();end++){
        curentsum+=nums[end];
        maxsum=max(curentsum,maxsum);
        
        
    }
    
   }
   cout<<maxsum;
    return 0;
}
