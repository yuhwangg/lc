/*680. Valid Palindrome II
Given a non-empty string s, you may delete at most one character. Judge whether you can make it
a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
*/


class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return isValid(s, i+1, j) || isValid(s, i, j-1);
            }
            ++i; --j;
        }
        return true;
    }
    bool isValid(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i; --j;
        }
        return true;
    }
};