class Solution
{
public:
    bool isValidBST(TreeNode *root, TreeNode *low = nullptr, TreeNode *high = nullptr)
    {
        if (!root)
            return true;

        if (low && root->val <= low->val)
            return false;

        if (high && root->val >= high->val)
            return false;

        return isValidBST(root->left, low, root) && isValidBST(root->right, root, high);
    }
};