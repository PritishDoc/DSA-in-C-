/*
Print thhe Partten of 1234 like a squre or print ABCD same way 
01234
01234
01234
01234

or

ABCDE
ABCDE
ABCDE
ABCDE
*/
#include<iostream>
using namespace std;

int main(){
    int n=5;
    char ch='A';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
         //   cout<<j;
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }
}