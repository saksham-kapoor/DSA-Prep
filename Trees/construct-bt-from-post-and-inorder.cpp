class Solution
{
    unordered_map<int, int> get_index;

    TreeNode *_build(vector<int> &in, vector<int> &pt, int in_s, int in_e, int pt_s, int pt_e)
    {
        if (in_s > in_e || pt_s > pt_e)
            return nullptr;

        TreeNode *root = new TreeNode(pt[pt_e]);
        int idx = get_index[pt[pt_e]]; // index of root in inorder
        int cnt = in_e - idx;          // count of nodes in right subtree

        root->left = _build(in, pt, in_s, idx - 1, pt_s, pt_e - cnt - 1);
        root->right = _build(in, pt, idx + 1, in_e, pt_e - cnt, pt_e - 1);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size() - 1;

        for (int i = 0; i <= n; ++i)
        {
            get_index[inorder[i]] = i;
        }

        return _build(inorder, postorder, 0, n, 0, n);
    }
};