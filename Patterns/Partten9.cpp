/*
Hollow Diamond Pattern

   *
  * *
 *   *
*     *
 *   *
  * *
   *

*/

#include<iostream>
using namespace std;

int main(){
    int n = 4; // Adjust the size of the diamond here

    // Top half (including middle line)
    for(int i = 0; i < n; i++){
        // Printing leading spaces
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        // Printing the first star
        cout << "*";

        // Printing spaces inside the diamond
        if(i != 0){
            for(int j = 0; j < 2 * i - 1; j++){
                cout << " ";
            }
            // Printing the second star
            cout << "*";
        }
        cout << endl;
    }

    // Bottom half
    for(int i = 1; i < n; i++){
        // Printing leading spaces
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        // Printing the first star
        cout << "*";

        // Printing spaces inside the diamond
        if(i != n - 1){
            for(int j = 0; j < 2 * (n - i - 1) - 1; j++){
                cout << " ";
            }
            // Printing the second star
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
