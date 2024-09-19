#include<iostream>
#include<vector>
using namespace std;

vector<int>Pairsum(vector<int>nums,int target){
    vector<int>ans;
     for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);

                return ans;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> nums={2,22,3,7};

    int target = 9 ;
    vector<int> ans= Pairsum(nums,target);
    cout<<ans[0]<<" , "<<ans[1]<<endl;
   
}