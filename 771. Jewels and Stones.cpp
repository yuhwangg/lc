/*771. Jewels and Stones

You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have.  
Each character in stones is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in jewels are guaranteed distinct, and all characters in jewels and S are letters. Letters are case sensitive,
so "a" is considered a different type of stone from "A".

Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0
*/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        unordered_set<char> s(jewels.begin(), jewels.end());
        for (char c : stones) {
        	if (s.count(c)) res++;
        }
        return res;
    }
};