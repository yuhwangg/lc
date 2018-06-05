class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode *root, int &res) {
        if (!root) return 0;
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        int sum = root->val + max(left, 0) + max(right, 0);
        res = max(res, sum);
        return max(max(left, right) + root->val, root->val); 
    }
};






