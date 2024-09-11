/*
    1
   121
  12321
 1234321
123454321

*/
#include<iostream>
using namespace std;

int main(){

    int n=5;
    for(int i=0;i<n;i++){
        //Now we printing space : n-i-1
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        //Now Printing the the number1
        for(int j=1;j<=i+1;j++){
            cout<<j;
        
        }
        //Printing the num2
        for(int j=i;j>0;j--){
            cout<<j;
        }
        cout<<endl;
    }
}