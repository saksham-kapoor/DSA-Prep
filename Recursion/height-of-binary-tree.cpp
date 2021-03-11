class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == 0)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};