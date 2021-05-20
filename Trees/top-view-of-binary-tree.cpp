class Solution
{
    map<int, pair<int, int>> mp;

    void dfs(Node *root, int x, int y)
    {
        if (!root)
            return;

        if (mp.find(x) != mp.end())
        {
            if (mp[x].first > y)
                mp[x] = {y, root->data};
        }
        else
        {
            mp[x] = {y, root->data};
        }

        dfs(root->left, x - 1, y + 1);
        dfs(root->right, x + 1, y + 1);
    }

public:
    vector<int> topView(Node *root)
    {
        vector<int> res;
        dfs(root, 0, 0);

        for (auto &p : mp)
        {
            res.push_back(p.second.second);
        }

        return res;
    }
};