struct BSTinfo
{
    int _min, _max, size, ans;
    bool isBST;

    BSTinfo(int mn, int mx, int sz, int a, bool BST)
    {
        _min = mn;
        _max = mx;
        size = sz;
        ans = a;
        isBST = BST;
    }
};

BSTinfo *solve(Node *root)
{
    if (!root)
        return new BSTinfo(INT_MAX, INT_MIN, 0, 0, true);

    if (!root->left && !root->right)
        return new BSTinfo(root->data, root->data, 1, 1, true);

    BSTinfo *left = solve(root->left);
    BSTinfo *right = solve(root->right);

    int data = root->data;
    int curr_ans = max(left->ans, right->ans);
    bool children = left->isBST && right->isBST;
    int sz = 1 + left->size + right->size;

    int mn = min(left->_min, root->data);
    int mx = max(right->_max, root->data);

    if (children && data > left->_max && data < right->_min)
        return new BSTinfo(mn, mx, sz, sz, true);

    return new BSTinfo(data, data, 0, curr_ans, false);
}

int largestBst(Node *root)
{
    BSTinfo *res = solve(root);
    return res->ans;
}