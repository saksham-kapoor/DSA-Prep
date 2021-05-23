class Solution
{

    TreeNode *find(TreeNode *root, int &p, int &q)
    {
        if (!root || p == root->val || q == root->val)
            return root;

        if (p < root->val && q < root->val)
            return find(root->left, p, q);

        if (p > root->val && q > root->val)
            return find(root->right, p, q);

        return root;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return find(root, p->val, q->val);
    }
};