#include<iostream>
#include<vector>
using namespace std;

vector<int>Pairsum(vector<int>nums,int target){
    vector<int>ans;
    int i=0, j=nums.size()-1;

    while(i<j){
        int pairsum = nums[i]+nums[j];
        if(pairsum > target){
            j--;
        }
        else if(pairsum < target){
            i++;
        }
        else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    
}
int main(){
    vector<int> nums={2,22,3,7};

    int target = 25 ;
    vector<int> ans= Pairsum(nums,target);
    cout<<ans[0]<<" , "<<ans[1]<<endl;
   
}