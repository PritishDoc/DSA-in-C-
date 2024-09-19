#include<iostream>
using namespace std;
//Brute Force Approch
int main(){
    int n=5;
    int arr[5]={1,2,3,4,5};
    int maxSum= INT8_MIN;
    for(int start=0;start<n;start++){
        int currentSum=0;
        for(int end=start; end<n; end++){
          
           currentSum += arr[end];
          maxSum =max(maxSum,currentSum);

            
        }
        
    }
    cout<<"Max subarray sum is: "<<maxSum;
    
}