/*438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will 
not be larger than 20,100.
The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input:
s: "abab" p: "ab"
Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> m;
        for (char c : p) m[c]++;
        int remaining = p.size();
        
        int i = 0, j = 0;
        while (j < s.size()) {
            if (m[s[j]] > 0) remaining--;
            m[s[j]]--;
            while (m[s[j]] < 0) { // this covers both duplicates and invalid char cases
                m[s[i]]++;
                if (m[s[i]] > 0) remaining++;
                i++;
            } 
            if (remaining == 0) res.push_back(i);
            j++;
        }
        return res;
    }
};