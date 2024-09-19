#include<iostream>
using namespace std;
//It also a  type of dp 
int main(){

    int n=5;
    int arr[5]={1,-2,3,-4,5};

    int currentSum=0;
    int MaxSum=INT8_MIN;
    for(int i=0;i<n;i++){
        currentSum +=arr[i];
        MaxSum = max(currentSum,MaxSum);
        if(currentSum <0){
            currentSum =0;//For reset    //Edge case if value goes into -ve
        }
    }

    cout<<"Maximum subArray is : "<<MaxSum;
}