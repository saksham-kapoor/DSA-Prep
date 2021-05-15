class Solution
{
    unordered_map<int, int> get_index;

    TreeNode *_build(vector<int> &in, vector<int> &pre, int in_s, int in_e, int pre_s, int pre_e)
    {

        if (in_s > in_e || pre_s > pre_e)
            return nullptr;

        TreeNode *root = new TreeNode(pre[pre_s]);

        int idx = get_index[pre[pre_s]]; // index of root in order
        int cnt = idx - in_s;            // number of nodes in left subtree

        // main concept!
        root->left = _build(in, pre, in_s, idx - 1, pre_s + 1, pre_s + cnt);
        root->right = _build(in, pre, idx + 1, in_e, pre_s + cnt + 1, pre_e);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size() - 1;

        for (int i = 0; i <= n; ++i)
        {
            get_index[inorder[i]] = i;
        }

        return _build(inorder, preorder, 0, n, 0, n);
    }
};