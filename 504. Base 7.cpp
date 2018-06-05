/* 504. Base 7
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"

Example 2:
Input: -7
Output: "-10" */

class Solution {
public:
    string convertToBase7(int n) {
        if (n < 0) 
            return "-" + convertToBase7(-n);
        else if (n < 7) 
            return to_string(n);
        else
            return convertToBase7(n/7) + to_string(n%7);
    }
};