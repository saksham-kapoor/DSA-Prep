int res;

int dfs(TreeNode *A)
{
    if (A == nullptr)
        return 0;

    int left = dfs(A->left);
    int right = dfs(A->right);

    int ans = max(A->val, A->val + max(left, right));
    res = max(res, max(ans, A->val + left + right));
    return ans;
}

int Solution::maxPathSum(TreeNode *A)
{
    res = INT_MIN;
    dfs(A);
    return res;
}