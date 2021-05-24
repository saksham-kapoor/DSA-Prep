class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p, TreeNode *mx = nullptr)
    {
        if (!root)
            return nullptr;

        if (p->val < root->val)
            return inorderSuccessor(root->left, p, root);
        if (p->val > root->val)
            return inorderSuccessor(root->right, p, mx);

        // p == root->val
        if (root->right)
        {
            p = p->right;
            while (p->left)
                p = p->left;
            return p;
        }

        // no right child, return parent if parent->val > this val
        if (mx)
            return mx;

        // else no inorder successor
        return nullptr;
    }
};