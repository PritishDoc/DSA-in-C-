#include<iostream>
using namespace std;

int main(){
    int n=5;
    int arr[5]={1,2,3,4,5};
    int maxSum=INT8_MIN;
    for(int st=0;st<n;st++){
        int currsum=0;
        for(int end=st;end<n;end++){
           currsum+=arr[end];
           maxSum=max(currsum,maxSum);
            
            
        }
        
        
    }
    cout<<"Max sum is : "<<maxSum;
}