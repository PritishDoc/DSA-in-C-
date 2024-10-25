#include<iostream>
using namespace std;

int main() {
    int size=6;
    int arr[size]={3,99,67,4,2,34};
    int smallest=INT16_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<smallest){
            smallest=arr[i];
        }
    }
    cout<<"Smallest = "<<smallest<<endl;
    return 0;
}