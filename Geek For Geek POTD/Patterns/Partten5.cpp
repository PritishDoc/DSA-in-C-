/*


1
22
333
4444
55555
666666
7777777
88888888
999999999
10101010101010101010
1111111111111111111111
121212121212121212121212
13131313131313131313131313
1414141414141414141414141414


*/
#include <iostream>
using namespace std;
int main()
{
    int n=15;
    for(int i=0;i<n;i++){
        for(int j=1;j<i+1;j++){
            cout<<i;
            
        }
        cout<<endl;
    }
    

    return 0;
}