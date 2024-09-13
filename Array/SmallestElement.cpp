#include<iostream>
using namespace std;

int main(){

    int nums[]={44,66,77,39,6,1};
    int size=6;
    int smallest=INT8_MAX;
    int largest=INT16_MIN;

    //For index
    int smallestIndex=0;
    int LargestIndex=0;
    for(int i=0;i<size;i++){
        if(nums[i]<smallest){
            smallest=nums[i];
            smallestIndex=i;
        }
        if(nums[i]>largest){
            largest=nums[i];
            LargestIndex=i;
        }
        smallest=min(nums[i],smallest);
        largest=max(nums[i],largest);
    }
    cout<<"Smallest = "<<smallest<<"Smallest index is: "<<smallestIndex<<endl;
    cout<<"Largest = "<<largest<<"Largest Index is : "<<LargestIndex<<endl;
}