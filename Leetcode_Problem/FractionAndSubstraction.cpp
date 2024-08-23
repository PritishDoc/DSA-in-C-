/*
. Fraction Addition and Subtraction
Medium
Topics
Companies
Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

 

Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"
Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"
 

Constraints:

The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1, 10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
*/
#include <string>
#include <numeric>
#include <sstream>

class Solution {
public:
    std::string fractionAddition(std::string expression) {
        int numerator = 0, denominator = 1;  // Start with 0/1
        
        for (int i = 0; i < expression.size(); ) {
            // Determine the sign of the current fraction
            int sign = 1;  // Default is positive
            if (expression[i] == '-' || expression[i] == '+') {
                sign = (expression[i] == '-') ? -1 : 1;
                i++;
            }
            
            // Parse the fraction numerator and denominator
            int num = 0, den = 0;
            while (i < expression.size() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i++;  // Skip the '/'
            while (i < expression.size() && isdigit(expression[i])) {
                den = den * 10 + (expression[i] - '0');
                i++;
            }
            
            // Add the current fraction to the accumulated fraction
            numerator = numerator * den + sign * num * denominator;
            denominator *= den;
            
            // Reduce the fraction by the greatest common divisor
            int gcd = std::gcd(abs(numerator), denominator);
            numerator /= gcd;
            denominator /= gcd;
        }
        
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};
