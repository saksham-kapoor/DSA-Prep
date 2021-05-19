// bfs
// right to left
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *res;

        while (q.size())
        {
            res = q.front();
            q.pop();

            if (res->right)
                q.push(res->right);
            if (res->left)
                q.push(res->left);
        }

        return res->val;
    }
};

// dfs
class Solution
{
    void dfs(TreeNode *root, int &mx_depth, int &res, int depth)
    {
        if (!root)
            return;

        dfs(root->left, mx_depth, res, depth + 1);
        dfs(root->right, mx_depth, res, depth + 1);

        if (depth > mx_depth)
        {
            mx_depth = depth;
            res = root->val;
        }
    }

public:
    int findBottomLeftValue(TreeNode *root)
    {
        int mx_depth = -1, res;
        dfs(root, mx_depth, res, 0);
        return res;
    }
};