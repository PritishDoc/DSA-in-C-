#include <iostream>
#include<algorithm>
using namespace std;
void sorting(int arr[],int n){
    sort(arr,arr+n);
    //return sorting;
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
/*
Best Case: 𝑂(𝑛log⁡𝑛)
O(nlogn) – This is when the array is already sorted or nearly sorted.
Average Case: 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn) – This is for an average unsorted array.
Worst Case: 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn) – Thanks to Introsort, which switches to HeapSort to maintain 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn) performance even in the worst case scenario
*/