class Solution
{
    bool hasCircle(int curr, const unordered_set<int> dep[], int vis[])
    {
        vis[curr] = 1;
        for (const int &d : dep[curr])
        {
            if (vis[d] == 2)
                continue;
            if (vis[d] == 1)
                return true;
            if (hasCircle(d, dep, vis))
                return true;
        }
        vis[curr] = 2;
        return false;
    }

public:
    bool isPrintable(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        // store position of colors
        // TIME : O(MN)
        unordered_map<int, array<int, 4>> pos;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                auto it = pos.find(grid[i][j]);
                if (it == pos.end())
                {
                    pos[grid[i][j]] = {i, j, i, j};
                }
                else
                {
                    it->second[0] = min(it->second[0], i);
                    it->second[1] = min(it->second[1], j);
                    it->second[2] = max(it->second[2], i);
                    it->second[3] = max(it->second[3], j);
                }
            }
        }

        unordered_set<int> adj[61];

        // TIME : O(CMN)
        for (auto &c : pos)
        {
            for (int i = c.second[0]; i <= c.second[2]; ++i)
            {
                for (int j = c.second[1]; j <= c.second[3]; ++j)
                {
                    if (grid[i][j] != c.first)
                    {
                        adj[grid[i][j]].insert(c.first);
                    }
                }
            }
        }

        int vis[61] = {};
        for (int i = 1; i <= 60; ++i)
        {
            if (!vis[i] && hasCircle(i, adj, vis))
                return false;
        }
        return true;
    }
};