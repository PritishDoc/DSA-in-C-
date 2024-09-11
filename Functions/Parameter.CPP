#include<iostream>
using namespace std;

int sum(int a,int b){//change datatype based on calculation
    return a+b;

}
//Minimum of Two num
int minOfTwo(int a,int b){//Parameters
    if(a<b){
        return a;
    }
    else return b;
}
int main(){
    cout<<sum(10,5)<<endl;
    cout<<minOfTwo(99,333);//Arguments
}
