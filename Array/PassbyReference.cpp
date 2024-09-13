#include<iostream>
using namespace std;
 void ChangeArr(int arr[],int size){
   for(int i=0;i<size;i++){
    arr[i]=2*arr[i];
   }
}
int main(){
    int arr[]={1,3,4};
    ChangeArr(arr,3);
    //Array in main 
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" "<<endl;
    }
}