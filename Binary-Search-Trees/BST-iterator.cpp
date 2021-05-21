class BSTIterator
{
public:
    vector<int> v;
    int idx;

    BSTIterator(TreeNode *root)
    {
        inorder(root);
        idx = -1;
    }

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    int next()
    {
        return v[++idx];
    }

    bool hasNext()
    {
        if (idx + 1 < v.size())
            return true;
        return false;
    }
};