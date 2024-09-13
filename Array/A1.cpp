#include<iostream>
using namespace std;

int main(){
    int marks[5]={33,99,89,46,66};

    double price[]={88.99,44.88,44.90,56.08};

    for(int i=0;i<sizeof(marks);i++){
            cout<<marks[i]<<endl;
    }
    //To Calculate the size of the Array
    cout<<sizeof(marks)/sizeof(int)<<endl;
  

}