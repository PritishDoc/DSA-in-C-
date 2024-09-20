#include<iostream>
using namespace std;
//Optimize approch  Approch
int main(){
    int n=5;
    int arr[5]={1,1,2,2,2};

        //First Sort the array
        sort(arr.begin(),arr.end());

        //freq count
        int freq=1;
        int ans=arr[0];

        for(int i=0;i<n;i++){
            if(nums[i]==nums[i-1]){
                freq++;
            }
            else{
                freq=1;
                ans=nums[i];
            }
        }
            
        }
        
    

    

//T(n)=