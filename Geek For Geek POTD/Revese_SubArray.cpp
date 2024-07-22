/*
Reverse sub array
Difficulty: BasicAccuracy: 31.78%Submissions: 21K+Points: 1
Provided an array Arr of N integers, you need to reverse a subarray of that array. The range of this subarray is given by indices L and R.

Example 1:

Input:
N = 7
Arr[] = {1, 2, 3, 4, 5, 6, 7}
L = 2, R = 4
Output:
1 4 3 2 5 6 7
Explanation: After reversing the elements 
in range 2 to 4 (2, 3, 4), 
modified array is 1, 4, 3, 2, 5, 6, 7.
Example 2:

Input:
N = 4
Arr[] = {1, 6, 7, 4}
L = 1, R = 4
Output:
4 7 6 1
Explanation: After reversing the elements
in range 1 to 4 (1, 6, 7, 4),
modified array is 4, 7, 6, 1.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function reverseSubArray() which takes the array of integers arr, n, l and r as parameters and returns void. You need to change the array itself.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 107
1 ≤ Arr[i] ≤ 106
1 ≤ L ≤ R ≤ N
*/

//User function template for C++
class Solution{
public:	
	void reverseSubArray(int *arr, int n, int l, int r) {
	    // code here
	    int start=l-1;
	    int end=r-1;
	    while(start<end){
	        swap(arr[start++],arr[end--]);
	    }
	}

};