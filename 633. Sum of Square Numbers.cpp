/*633. Sum of Square Numbers

Given a non-negative integer c, your task is to decide whether there're two integers a and b 
such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: 3
Output: False*/


class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = sqrt(c); i >= 0; --i) {
            if (i * i == c) return true;
            int d = c - i * i;
            int t = sqrt(d);
            if (t * t == d) return true;
        }
        return false;
    }
};