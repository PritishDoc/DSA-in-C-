/*
1
21
321
4321
54321

*/

#include<iostream>
using namespace std;

int main(){
int n=6;
    for(int i=0;i<n;i++){
        for(int j=i+1;j>0;j--){
            cout<<j<<" ";

        }
        cout<<endl;
    }
}