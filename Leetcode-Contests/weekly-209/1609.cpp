// BFS SOLUTION!
class Solution
{
public:
    bool isEvenOddTree(TreeNode *root)
    {
        if (root->val % 2 == 0)
            return false;

        queue<pair<TreeNode *, int>> nodes;
        int odd = INT_MIN, even = INT_MAX;

        nodes.push({root->left, 1});
        nodes.push({root->right, 1});

        while (!nodes.empty())
        {
            pair<TreeNode *, int> node = nodes.front();
            nodes.pop();

            if (node.first == nullptr)
                continue;

            int level = node.second;

            if (level & 1)
            {
                odd = INT_MIN;
                if (node.first->val % 2 == 1 || even <= node.first->val)
                    return false;

                even = node.first->val;
            }
            else
            {
                even = INT_MAX;
                if (node.first->val % 2 == 0 || odd >= node.first->val)
                    return false;

                odd = node.first->val;
            }

            nodes.push({node.first->left, level + 1});
            nodes.push({node.first->right, level + 1});
        }

        return true;
    }
};

// DFS SOLUTION! -> LESS EFFICIENT IN THIS CASE!
class Solution
{
    unordered_map<int, int> lastVal;
    bool dfs(TreeNode *root, int level)
    {
        if (!root)
            return true;

        // odd level
        if (level & 1)
        {
            if (root->val % 2 == 1)
                return false;

            if (lastVal[level] != 0 && lastVal[level] <= root->val)
                return false;

            lastVal[level] = root->val;
        }
        else
        {
            if (root->val % 2 == 0)
                return false;

            if (lastVal[level] != 0 && lastVal[level] >= root->val)
                return false;

            lastVal[level] = root->val;
        }

        bool ans;
        ans = dfs(root->left, level + 1) && dfs(root->right, level + 1);
        return ans;
    }

public:
    bool isEvenOddTree(TreeNode *root)
    {
        return dfs(root, 0);
    }
};