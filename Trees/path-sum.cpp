// ITERATIVE SOLUTION
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        queue<pair<TreeNode *, int>> nodes;
        nodes.push({root, targetSum});

        while (nodes.size())
        {
            auto [node, sum] = nodes.front();
            nodes.pop();

            if (!node)
                continue;

            sum -= node->val;

            if (!node->left && !node->right)
            {
                if (sum == 0)
                    return true;
                continue;
            }

            nodes.push({node->left, sum});
            nodes.push({node->right, sum});
        }

        return false;
    }
};

// BOTTOM UP RECURSION
class Solution
{
    bool solve(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        targetSum -= root->val;

        if (!root->left && !root->right)
            return !targetSum;

        return solve(root->left, targetSum) || solve(root->right, targetSum);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return solve(root, targetSum);
    }
};

// TOP DOWN RECURSION
class Solution
{
    bool solve(TreeNode *root, int curr, int targetSum)
    {
        curr += root->val;

        if (!root->left && !root->right)
            return curr == targetSum;

        int ans = false;

        if (root->left)
            ans = ans || solve(root->left, curr, targetSum);
        if (root->right)
            ans = ans || solve(root->right, curr, targetSum);

        return ans;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        return solve(root, 0, targetSum);
    }
};