#include <iostream>
#include<algorithm>
using namespace std;
void sorting(string arr[],int n){
   
    int start=0;
    int end=n-1;
    while(start<end){
        swap(arr[start++],arr[end--]);
    }
  
   }
    

int main()
{
    string arr[11]={"2","8","9","2","0","0","1","4","5","44","14"};
    
   sorting(arr,11);
   cout<<"The sorted array is : ";
   for(int i=0;i<11;i++){
       cout<<arr[i]<<" ";
       
   }cout<<endl;
    return 0;
}