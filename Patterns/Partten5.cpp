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

A
BB
CCC
DDDD
EEEEE
FFFFFF
GGGGGGG
HHHHHHHH
IIIIIIIII
JJJJJJJJJJ
KKKKKKKKKKK
LLLLLLLLLLLL
MMMMMMMMMMMMM
NNNNNNNNNNNNNN
OOOOOOOOOOOOOOO

*/
#include <iostream>
using namespace std;
int main()
{
    int n=15;
    char ch='A';
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
          // cout<<i;
          cout<<ch;
            
        }
        ch++;
        cout<<endl;
    }
    

    return 0;
}