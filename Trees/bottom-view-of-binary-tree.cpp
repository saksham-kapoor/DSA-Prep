void dfs(Node *root, int x, int y, map<int, pair<int, int>> &mp)
{
    if (!root)
        return;

    if (mp.find(x) != mp.end())
    {
        if (y >= mp[x].first)
            mp[x] = {y, root->data};
    }
    else
    {
        mp[x] = {y, root->data};
    }

    dfs(root->left, x - 1, y + 1, mp);
    dfs(root->right, x + 1, y + 1, mp);
}

vector<int> bottomView(Node *root)
{
    vector<int> res;
    map<int, pair<int, int>> mp;
    dfs(root, 0, 0, mp);

    for (auto &p : mp)
    {
        res.push_back(p.second.second);
    }

    return res;
}