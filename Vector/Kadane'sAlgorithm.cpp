#include <iostream>
#include <vector>

using namespace std;




int main() {
    vector<int> nums = {1,2,3,4,5,6};
    int maxsum=INT16_MIN;
     int curentsum=0;
   for(int val : nums){
   
   
        curentsum+=val;
        maxsum=max(curentsum,maxsum);
        
        if(curentsum<0){
            curentsum=0;
        }
   }
    
    
   
   cout<<curentsum;
    return 0;
}
