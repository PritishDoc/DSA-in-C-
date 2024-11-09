/*
Minimum sum
Difficulty: MediumAccuracy: 17.14%Submissions: 128K+Points: 4
Given an array arr[] such that each element is in the range [0 - 9], find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers. Return a string without leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: 604
Explanation: The minimum sum is formed by numbers 358 and 246.
Input: arr[] = [5, 3, 0, 7, 4]
Output: 82
Explanation: The minimum sum is formed by numbers 35 and 047.
Input: arr[] = [9, 4]
Output: 13
Explanation: The minimum sum is formed by numbers 9 and 4.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 9

*/
class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort( arr.begin(), arr.end(), greater<int>() );
        int n = arr.size(), sum=0;
        vector<char> v;
        for( int i=0; i<n; i+=2 ) {
            sum += arr[i];
            if( (i+1) < n )
                sum += arr[i+1];
            v.push_back( '0' + sum%10 );
            sum = sum/10;
        }
        if( sum )
            v.push_back( '0' + sum );
        while( v.back() == '0' )
            v.pop_back();
        return string( v.rbegin(), v.rend() );
    }
};