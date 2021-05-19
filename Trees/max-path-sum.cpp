// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution
{
    int dfs(TreeNode *root, int &res)
    {
        if (!root)
            return 0;

        int left_ans = dfs(root->left, res);
        int right_ans = dfs(root->right, res);

        int ans = root->val;
        ans = max(ans, max(ans + left_ans, ans + right_ans));
        res = max(res, max(ans, root->val + left_ans + right_ans));
        return ans;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};