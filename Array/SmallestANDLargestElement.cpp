#include<iostream>
using namespace std;

int main() {
    int size=6;
    int arr[size]={3,99,67,4,2,34};
    int smallest=INT16_MAX;
      int largest=INT16_MIN;

      
      
    for(int i=0;i<size;i++){
        if(arr[i]<smallest){
            smallest=arr[i];
        }
        //or we can write 
        smallest=min(arr[i],smallest);

      
        largest=max(arr[i],largest);
        
    }
    cout<<"Smallest element  = "<<smallest<<endl;
    cout<<"Largest element = "<<largest<<endl;
    return 0;
}