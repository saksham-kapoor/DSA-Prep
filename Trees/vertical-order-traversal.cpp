typedef pair<int, int> pii;

class Solution
{

    struct comp
    {
        bool operator()(pii &a, pii &b)
        {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        }
    };

    map<int, priority_queue<pii, vector<pii>, comp>> mp;

    void dfs(TreeNode *root, int k, int lvl)
    {
        if (!root)
            return;

        mp[k].emplace(lvl, root->val);
        dfs(root->left, k - 1, lvl + 1);
        dfs(root->right, k + 1, lvl + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;
        dfs(root, 0, 0);

        for (auto &[k, heap] : mp)
        {
            res.push_back({heap.top().second});
            heap.pop();
            while (heap.size())
            {
                res.back().push_back(heap.top().second);
                heap.pop();
            }
        }

        return res;
    }
};