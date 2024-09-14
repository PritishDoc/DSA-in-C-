#include<iostream>
using namespace std;
int SwapArray(int arr[],int size){
    int start=0;
    int end=size-1;

 while(start<end){
    swap(arr[start],arr[end]);
    start++;
    end--;
 }
       return -1;
    }
    

int main(){
    int arr[]={4,5,6,3,9,1};
    int size=6;
    
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    SwapArray(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

}