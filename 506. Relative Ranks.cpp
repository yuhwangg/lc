/* 506. Relative Ranks
Given scores of N athletes, find their relative ranks and the people with the top three highest scores,
who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", 
"Silver Medal" and "Bronze Medal". For the left two athletes, you just need to output their relative ranks 
according to their scores. */

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<string> res(n, "");
        priority_queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            q.push({nums[i], i});
        }
        int k = 1;
        for(int i=0; i<n; i++){
            int idx = q.top().second;
            q.pop();
            if(k==1) res[idx] = "Gold Medal";
            else if(k==2) res[idx] = "Silver Medal";
            else if (k==3) res[idx] = "Bronze Medal";
            else res[idx] = to_string(k);
            k++;
        }
        return res;
    }
};