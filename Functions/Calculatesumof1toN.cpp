#include<iostream>
using namespace std;

int  sum(int n){
    int sum=0;
    for(int i=0;i<=n;i++){
        sum +=i;
    }
    return sum;
}

int main(){
    cout<<sum(55)<<endl;
    cout<<sum(100)<<endl;
}