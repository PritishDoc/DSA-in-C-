#include<iostream>
using namespace std;

int sum(int a,int b){
    a+=10;
    b+=10;
    return a+b;
}
int main(){
    int a=5;
    int b=5;
    cout<<sum(a,b)<<endl;
    cout<<a<<" "<<b; 
}