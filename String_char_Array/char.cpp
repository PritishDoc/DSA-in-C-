#include<iostream>
using namespace std;

int main(){

    char name[20];
    cout<<"Enter your name"<<endl;
    cin>>name;
    name[2]='\0';//we added null value 
    //after null value compiler doesnot print anything 
    

    cout<<"Your name is : ";
    cout<<name<<endl;

    return 0;
}