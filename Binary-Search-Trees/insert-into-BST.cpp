// Elegant Code without a bunch of 'if' statements
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int &val)
    {
        if (!root)
            return new TreeNode(val);

        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);

        return root;
    }
};

// Readable Code
class Solution
{
    void insert(TreeNode *root, int &val)
    {
        if (val < root->val)
        {
            if (root->left)
                insert(root->left, val);
            else
                root->left = new TreeNode(val);
        }
        else
        {
            if (root->right)
                insert(root->right, val);
            else
                root->right = new TreeNode(val);
        }
    }

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);

        insert(root, val);
        return root;
    }
};