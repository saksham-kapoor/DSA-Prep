// ITERATIVE SOLUTION
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> nodes;
        nodes.push(root->left);
        nodes.push(root->right);

        while (nodes.size())
        {
            TreeNode *l = nodes.front();
            nodes.pop();

            TreeNode *r = nodes.front();
            nodes.pop();

            if (!l && !r)
                continue;

            if (!l || !r || l->val != r->val)
                return false;

            nodes.push(l->left);
            nodes.push(r->right);
            nodes.push(l->right);
            nodes.push(r->left);
        }

        return true;
    }
};

// RECURSIVE SOLUTION
class Solution
{
    bool check(TreeNode *l, TreeNode *r)
    {
        if (!l || !r)
            return l == r;

        if (l->val != r->val)
            return false;

        return check(l->left, r->right) && check(l->right, r->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return check(root->left, root->right);
    }
};