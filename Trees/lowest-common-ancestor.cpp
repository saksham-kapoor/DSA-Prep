class Solution
{
    TreeNode *_find(TreeNode *root, int &p, int &q)
    {
        if (!root || root->val == p || root->val == q)
            return root;

        TreeNode *left_ans = _find(root->left, p, q);
        TreeNode *right_ans = _find(root->right, p, q);

        if (left_ans && right_ans)
            return root;

        return (left_ans != nullptr ? left_ans : right_ans);
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return _find(root, p->val, q->val);
    }
};