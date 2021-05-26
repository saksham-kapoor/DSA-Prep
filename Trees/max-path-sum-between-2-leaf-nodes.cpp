class Solution
{
    int res;

    int dfs(Node *root, int &res)
    {
        if (!root)
            return INT_MIN;

        if (!root->left && !root->right)
            return root->data;

        int l = dfs(root->left, res);
        int r = dfs(root->right, res);

        int ans = max(l, r) + root->data;

        if (!root->left || !root->right)
            return ans;

        res = max(res, l + r + root->data);
        return ans;
    }

public:
    int maxPathSum(Node *root)
    {
        res = INT_MIN;
        int val = dfs(root, res);
        if (res == INT_MIN)
            return val;
        return res;
    }
};