// TOP DOWN SOLUTION
class Solution
{
    void find(TreeNode *root, int d, int &ans)
    {
        if (!root)
            return;

        if (!root->left && !root->right) // leaf node
            ans = max(ans, d);

        find(root->left, d + 1, ans);
        find(root->right, d + 1, ans);
    }

public:
    int maxDepth(TreeNode *root)
    {
        int ans = 0;
        find(root, 1, ans);
        return ans;
    }
};

// BOTTOM UP SOLUTION
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};