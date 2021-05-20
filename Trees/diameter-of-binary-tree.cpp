class Solution
{
    int res;

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        res = max(res, left + right);
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        res = 0;
        dfs(root);

        return res;
    }
};