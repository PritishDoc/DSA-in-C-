#include<iostream>
#include<algorithm> // for sort
using namespace std;

int main(){
    int n = 5;
    int arr[5] = {1, 1, 2, 2, 2};

   int freq=0, ans=0;
   for(int i=0;i<n;i++){
    if(freq==0){
        ans =arr[i];
    }
    if(ans==arr[i]){
    freq++;
    }
    else{
    freq--;
    }
    }
   
    
    cout << "Most frequent element is: " << ans << endl;
    
    return 0;
}
//t(n)=O(nlogn)
