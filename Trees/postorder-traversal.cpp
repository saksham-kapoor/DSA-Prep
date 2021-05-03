// ITERATIVE SOLUTION
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        stack<pair<TreeNode *, int>> s;
        s.push({root, 0});

        while (!s.empty())
        {
            pair<TreeNode *, int> curr = s.top();
            s.pop();

            if (curr.first == nullptr || curr.second == 3)
                continue;

            s.push({curr.first, curr.second + 1});

            if (curr.second == 0)
                s.push({curr.first->left, 0});
            else if (curr.second == 1)
                s.push({curr.first->right, 0});
            else if (curr.second == 2)
                ans.push_back(curr.first->val);
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

        traverse(root->left, ans);
        traverse(root->right, ans);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};