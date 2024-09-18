#include<vector>
#include<iostream>
using namespace std;

int main(){

    vector<int> vec={3,4,5,9};

    for(int val:vec){
        cout<<val<<endl;
    }
    cout<<"Size = "<<vec.size()<<endl;

    //To push an element
    vec.push_back(33);
    cout<<"Size = "<<vec.size()<<endl;

    vec.pop_back(5);
     cout<<"Size = "<<vec.size()<<endl;
}