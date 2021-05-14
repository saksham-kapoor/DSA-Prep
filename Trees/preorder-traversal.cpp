class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        stack<pair<TreeNode *, int>> st;
        st.push({root, 0});

        while (st.size())
        {
            auto [node, level] = st.top();
            st.pop();

            if (node == nullptr || level == 3)
                continue;

            st.push({node, level + 1});

            if (level == 0)
            {
                ans.push_back(node->val);
            }
            else if (level == 1)
            {
                st.push({node->left, 0});
            }
            else if (level == 2)
            {
                st.push({node->right, 0});
            }
        }

        return ans;
    }
};

// Simple stack solution
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        stack<TreeNode *> st;
        st.push(root);

        while (st.size())
        {
            TreeNode *node = st.top();
            st.pop();

            if (node == nullptr)
                continue;

            ans.push_back(node->val); // print
            st.push(node->right);
            st.push(node->left);
        }

        return ans;
    }
};

// RECURSIVE SOLUTION
class Solution
{

    void traverse(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        ans.push_back(root->val);
        traverse(root->left, ans);
        traverse(root->right, ans);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};