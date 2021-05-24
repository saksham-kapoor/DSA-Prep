class Solution
{
public:
    TreeNode *inorderPredecessor(TreeNode *root, TreeNode *p, TreeNode *mn = nullptr)
    {
        if (!root)
            return nullptr;

        if (p->val < root->val)
            return inorderPredecessor(root->left, p, mn);
        if (p->val > root->val)
            return inorderPredecessor(root->right, p, root);

        // p == root
        if (root->left)
        {
            p = p->left;
            while (p->right)
                p = p->right;
            return p;
        }

        // no left node
        // check parent
        if (mn)
            return mn;
        return nullptr;
    }
};