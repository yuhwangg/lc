/*Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers 
on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in
the triangle.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &t) {
        int n = t.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < t[i].size(); ++j) {
                if (j == 0) t[i][j] += t[i - 1][j];
                else if (j == t[i].size() - 1) t[i][j] += t[i-1][j-1];
                else {
                    t[i][j] += min(t[i-1][j-1], t[i-1][j]);
                }
            }
        }
        int res = t[n-1][0];
        for (int i = 0; i < t[n-1].size(); ++i) {
            res = min(res, t[n-1][i]);
        }
        return res;
    }
};





