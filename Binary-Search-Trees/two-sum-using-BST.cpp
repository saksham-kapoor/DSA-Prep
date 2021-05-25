// BST Iterator Class
// O(n) time, O(logN) space
class BSTIterator
{
    stack<TreeNode *> st;
    bool forward;

    void fillstack(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = forward ? node->left : node->right;
        }
    }

public:
    BSTIterator(TreeNode *root, bool forward) : forward(forward)
    {
        fillstack(root);
    }

    int next()
    {
        TreeNode *res = st.top();
        st.pop();
        fillstack(forward ? res->right : res->left);
        return res->val;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTIterator l(root, true);
        BSTIterator r(root, false);

        int i = l.next(), j = r.next();
        while (i < j)
        {
            int sum = i + j;
            if (sum < k)
                i = l.next();
            else if (sum > k)
                j = r.next();
            else
                return true;
        }

        return false;
    }
};

// O(n) space, O(n) time
class Solution
{
    void inorder(TreeNode *root, vector<int> &in)
    {
        if (!root)
            return;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> in;
        inorder(root, in);

        int i = 0, j = in.size() - 1;
        while (i < j)
        {
            int sum = in[i] + in[j];
            if (sum < k)
                ++i;
            else if (sum > k)
                --j;
            else
                return true;
        }

        return false;
    }
};