#include<iostream>
using namespace std;

int CalculateFactorialofN(int n){
    long fact=1;
    for(int i=1;i<=n;i++){
        fact =fact * i;
    }
    return fact;
}

int main(){
    cout<<CalculateFactorialofN(10)<<endl;
    cout<<CalculateFactorialofN(5)<<endl;
}