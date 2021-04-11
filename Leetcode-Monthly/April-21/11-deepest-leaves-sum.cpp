class Solution
{
    int getLength(TreeNode *p)
    {
        if (p == nullptr)
            return 0;
        return 1 + max(getLength(p->left), getLength(p->right));
    }
    int calculateSum(TreeNode *p, int h)
    {
        if (p == nullptr)
            return 0;
        if (h == 1)
            return p->val;
        return calculateSum(p->left, h - 1) + calculateSum(p->right, h - 1);
    }

public:
    int deepestLeavesSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int height = getLength(root);
        return calculateSum(root, height);
    }
};