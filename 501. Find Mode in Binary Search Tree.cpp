/*501. Find Mode in Binary Search Tree

Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred 
element) in the given BST.

Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2

return [2].

Note: If a tree has more than one mode, you can return them in any order.
Follow up: Could you do that without using any extra space? (Assume that the implicit stack space 
    incurred due to recursion does not count). */

/*这道题让我们求二分搜索树中的众数，这里定义的二分搜索树中左根右结点之间的关系是小于等于的，有些题目中是严格小于的，
所以一定要看清题目要求。所谓的众数就是出现最多次的数字，可以有多个，那么这道题比较直接点思路就是利用一个哈希表来记录
数字和其出现次数之前的映射，然后维护一个变量mx来记录当前最多的次数值，这样在遍历完树之后，根据这个mx值就能把对应的元
素找出来, 用这种方法的话就不需要用到二分搜索树的性质了，随意一种遍历方式都可以，下面我们来看递归的中序遍历的解法如下*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        int maxfeq = 0;
        unordered_map<int, int> m;
        inorder(root, m, maxfeq);
        for (auto a : m){
            if (a.second == maxfeq) 
                res.push_back(a.first);
        }
        return res;
    }
    
    void inorder(TreeNode *node, unordered_map<int,int> &m, int &maxfeq){
        if(!node) return;
        m[node->val]++;
        inorder(node->left, m, maxfeq);
        maxfeq = max(maxfeq, m[node->val]);
        inorder(node->right, m, maxfeq);
    }
};






