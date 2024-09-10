/*
Print The number series like 
123
456
789... so on

*/
#include<iostream>

using namespace std;
int main(){
    int num=0;
    int n=3;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<num;
            num++;
        }
        cout<<endl;
    }
}