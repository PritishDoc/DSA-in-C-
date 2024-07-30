#include<iostream>
#include<vector>
using namespace std;
void merge(int arr1[],int n,int arr2[],int m,int arr3[]){
    int i=0;int j=0;
    int k=0;
    
    while(i<n && j<m){
        if(arr1[i]< arr2[j]){
        
             arr3[k++]=arr1[i++];

        }
        else{
            arr3[k++]=arr2[j++];
        }
    }
    //copy remaning element of arr1
     while(i<n){
        arr3[k++]=arr1[i++];

     }
     //copy remaning element of arr2
     while(j<m){
        arr3[k++]=arr2[j++];
     }
}
void print(int arr3[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
}
int main(){

    int arr1[5]={1,2,3,5,7};
    int arr2[3]={9,11,44};
    int arr3[8];
    merge(arr1,5,arr2,3,arr3);
    print(arr3,8);
    return 0;
}