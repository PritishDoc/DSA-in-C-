#include<iostream>
using namespace std;
int LinearSearch(int arr[],int size,int target){
 for(int i=0;i<size;i++){
        if(arr[i]==target){
            cout<<"The Target Element is : "<<i;
        }
       
    }
    return -1;
}
int main(){
    int arr[]={4,5,6,3,9,1};
    int size=6;
    int target=11;
    cout<<LinearSearch(arr,size,target)<<endl;
}