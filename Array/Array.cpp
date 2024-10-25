#include<iostream>
using namespace std;

int main() {
    int marks[7];
    double price[56] = {33.45, 44.99, 44.89, 98, 88};

    // Calculate the size of the marks array
    int sz = sizeof(marks) / sizeof(int);

    // Taking input for the marks array
    for(int i = 0; i < sz; i++) {
        cin >> marks[i];
    }

    cout << sz << endl; // Print the total number of elements in the marks array

    // Printing the elements of the marks array
    for(int i = 0; i < sz; i++) {
        cout << marks[i] << endl;
    }
    cout << endl;

    return 0;
}
