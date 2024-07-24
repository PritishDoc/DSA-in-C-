#include<iostream>
using namespace std;

int getLength(char name[]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }
    return count ;
}
int main(){

    char name[20];
    cout<<"Enter your name"<<endl;
    cin>>name;
   // name[2]='\0';//we added null value 
    //after null value compiler doesnot print anything 
    

    cout<<"Your name is : ";
    cout<<name<<endl;
    cout<<"Length is : "<<getLength(name)<<endl;
    return 0;
}