/*
Divide Players Into Teams of Equal Skill
Medium
Topics
Companies
Hint
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

 

Example 1:

Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation: 
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
Example 2:

Input: skill = [3,4]
Output: 12
Explanation: 
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.
Example 3:

Input: skill = [1,1,2,3]
Output: -1
Explanation: 
There is no way to divide the players into teams such that the total skill of each team is equal.
 

Constraints:

2 <= skill.length <= 105
skill.length is even.
1 <= skill[i] <= 1000

*/

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long S = 0;
        for(auto s : skill) S += s;
        
        // Check if 2*S is divisible by n
        if((2 * S) % n != 0) return -1;
        
        long long target = (2 * S) / n;
        
        // Initialize frequency array
        vector<int> freq(1001, 0);
        for(auto s : skill) freq[s]++;
        
        long long sumChemistry = 0;
        
        // Iterate through possible skill values
        for(int a = 1; a <= 1000; a++) {
            while(freq[a] > 0){
                int b = target - a;
                
                // Check if b is within valid range
                if(b <1 || b >1000) return -1;
                
                // Check if the complement exists
                if(freq[b] == 0) return -1;
                
                if(a == b){
                    if(freq[a] <2) return -1;
                    sumChemistry += (long long)a * b;
                    freq[a] -=2;
                }
                else{
                    if(freq[b] <1) return -1;
                    sumChemistry += (long long)a * b;
                    freq[a]--;
                    freq[b]--;
                }
            }
        }
        
        return sumChemistry;
    }
};
