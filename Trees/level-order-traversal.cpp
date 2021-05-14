// ITERATIVE SOLUTION
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (!root)
            return ans;

        queue<pair<TreeNode *, int>> nodes;
        nodes.push({root, 1});

        while (nodes.size())
        {
            auto [node, level] = nodes.front();
            nodes.pop();

            if (node == nullptr)
                continue;

            if (ans.size() < level)
                ans.push_back({node->val});
            else
                ans[level - 1].push_back(node->val);

            nodes.push({node->left, level + 1});
            nodes.push({node->right, level + 1});
        }

        return ans;
    }
};

// RECURSIVE SOLUTION
class Solution
{

    int get_levels(TreeNode *root)
    {
        if (!root)
            return 0;

        return 1 + max(get_levels(root->left), get_levels(root->right));
    }

    void traverse(TreeNode *root, int level, vector<vector<int>> &ans)
    {
        if (!root)
            return;

        ans[level].push_back(root->val);
        traverse(root->left, level + 1, ans);
        traverse(root->right, level + 1, ans);
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        int levels = get_levels(root);
        vector<vector<int>> ans(levels);

        traverse(root, 0, ans);

        return ans;
    }
};