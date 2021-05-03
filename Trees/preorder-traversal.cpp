// ITERATIVE SOLUTION
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
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
                ans.push_back(curr.first->val);
            else if (curr.second == 1)
                s.push({curr.first->left, 0});
            else if (curr.second == 2)
                s.push({curr.first->right, 0});
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