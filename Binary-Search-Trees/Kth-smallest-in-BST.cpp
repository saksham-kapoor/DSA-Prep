// BST Iterator Method!
// O(N) time, O(logN) space
class Solution
{
    void fillStack(TreeNode *node, stack<TreeNode *> &st)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> st;
        fillStack(root, st);

        while (k-- != 1)
        {
            TreeNode *res = st.top();
            st.pop();

            fillStack(res->right, st);
        }

        return st.top()->val;
    }
};

// SLOW BUT WORKING
// O(N^2) TIME IN WORST, O(N) STACK SPACE
class Solution
{
    int count(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = count(root->left);
        int right = count(root->right);
        return 1 + left + right;
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        if (k == 1 && !root->left)
            return root->val;

        int count_left = count(root->left);
        if (k == count_left + 1)
            return root->val;

        if (k > count_left)
            return kthSmallest(root->right, k - count_left - 1);

        return kthSmallest(root->left, k);
    }
};