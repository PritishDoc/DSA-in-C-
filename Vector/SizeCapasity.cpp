#include<vector>
#include<iostream>
using namespace std;

int main(){

    vector<int> vec;

    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    cout<<vec.size()<<endl;//5
    cout<<vec.capacity()<<endl;

}