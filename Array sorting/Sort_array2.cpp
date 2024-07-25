#include <iostream>
#include<algorithm>
using namespace std;
void sorting(int arr[],int n){
   
   for(int i=0;i<n-1;i++){
       for(int j=0;j<n-i-1;j++){
           if(arr[j]>arr[j+1]){
               swap(arr[j],arr[j+1]);
           }
       }
   }
    
}
int main()
{
    int arr[11]={2,8,9,2,0,0,1,4,5,44,13};
    
   sorting(arr,11);
   cout<<"The sorted array is : ";
   for(int i=0;i<11;i++){
       cout<<arr[i]<<" ";
       
   }cout<<endl;
    return 0;
}