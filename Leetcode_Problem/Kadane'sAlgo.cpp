#include<iostream>
using namespace std;

int main(){


    
    int arr[5]={1,3,-4,8,-3};

    int currsum=0;
    int maxsum=INT8_MIN;
    int n=5;
    for(int i=0;i<n;i++){
        currsum+=arr[i];
        maxsum=max(currsum,maxsum);
        if(currsum<0){
            currsum=0;
        }
    }
    cout<<maxsum;
}