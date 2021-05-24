// O(n) solution! [REFACTORED]
class Solution
{
    int idx = 0;

public:
    TreeNode *bstFromPreorder(vector<int> &p, int mx = INT_MAX)
    {
        if (idx == p.size() || p[idx] > mx)
            return nullptr;

        TreeNode *root = new TreeNode(p[idx++]);
        root->left = bstFromPreorder(p, root->val);
        root->right = bstFromPreorder(p, mx);
        return root;
    }
};

// O(n) solution!
class Solution
{
    int idx = 0;

public:
    TreeNode *bstFromPreorder(vector<int> &p, int mx = INT_MAX)
    {
        TreeNode *root = new TreeNode(p[idx++]);

        if (idx < p.size() && p[idx] < root->val)
            root->left = bstFromPreorder(p, root->val);

        if (idx < p.size() && p[idx] > root->val && p[idx] < mx)
            root->right = bstFromPreorder(p, mx);

        return root;
    }
};

// SET (NlogN) Solution
class Solution
{
    set<int> in;
    TreeNode *construct(vector<int> &p, int in_s, int in_e, int p_s, int p_e)
    {
        if (p_s > p_e || in_s > in_e)
            return nullptr;

        TreeNode *root = new TreeNode(p[p_s]);
        auto it = in.find(p[p_s]);
        int idx = distance(in.begin(), it);
        int cnt = idx - in_s;

        root->left = construct(p, in_s, idx - 1, p_s + 1, p_s + cnt);
        root->right = construct(p, idx + 1, in_e, p_s + cnt + 1, p_e);

        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &p)
    {
        for (int i = 0; i < p.size(); ++i)
            in.insert(p[i]);

        return construct(p, 0, p.size() - 1, 0, p.size() - 1);
    }
};