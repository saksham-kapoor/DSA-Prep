// Trace out this 2 stack solution
class Solution
{
    vector<vector<int>> res;

    void traverse(stack<pair<TreeNode *, int>> &st, stack<pair<TreeNode *, int>> &new_st)
    {
        int size = st.size();

        for (int i = 0; i < size; ++i)
        {
            auto [node, lvl] = st.top();
            st.pop();

            if (lvl > res.size())
                res.push_back({node->val});
            else
                res[lvl - 1].push_back(node->val);

            if (lvl & 1)
            {
                if (node->left)
                    new_st.emplace(node->left, lvl + 1);
                if (node->right)
                    new_st.emplace(node->right, lvl + 1);
                continue;
            }

            if (node->right)
                new_st.emplace(node->right, lvl + 1);
            if (node->left)
                new_st.emplace(node->left, lvl + 1);
        }
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return res;

        stack<pair<TreeNode *, int>> st1;
        stack<pair<TreeNode *, int>> st2;
        st1.emplace(root, 1);

        while (st1.size() || st2.size())
        {
            if (st1.size() > st2.size())
                traverse(st1, st2);
            else
                traverse(st2, st1);
        }

        return res;
    }
};