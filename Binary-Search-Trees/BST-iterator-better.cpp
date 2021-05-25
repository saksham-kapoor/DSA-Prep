class BSTIterator
{
    stack<TreeNode *> st;

    void fillstack(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        fillstack(root);
    }

    int next()
    {
        TreeNode *res = st.top();
        st.pop();
        fillstack(res->right);
        return res->val;
    }

    bool hasNext()
    {
        return st.size();
    }
};