/*
103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, 
then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Assuming after traversing the 1st level, nodes in queue are {9, 20, 8}, And we are going to traverse 
2nd level, which is even line and should print value from right to left [8, 20, 9].

We know there are 3 nodes in current queue, so the vector for this level in final result should be of size 3.
Then, queue [i] -> goes to -> vector[queue.size() - 1 - i]i.e. the ith node in current queue should be placed 
in (queue.size() - 1 - i) position in vector for that line.

For example, for node(9), it's index in queue is 0, so its index in vector should be (3-1-0) = 2.*/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;    
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool left2right = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> row(n);
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = (left2right) ? i : (n-1-i);
                row[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

            }
            // after each level
            left2right = !left2right;
            res.push_back(row);
        }
        return res;
    }
};








