class Solution
{
    int m, n, d[5] = {-1, 0, 1, 0, -1};

    void dfs(int x, int y, vector<vector<int>> &g1, vector<vector<int>> &g2, bool &ans)
    {
        if (x < 0 || y < 0 || x == m || y == n || g2[x][y] == 0)
            return;

        if (g1[x][y] == 0)
            ans = false;

        g2[x][y] = 0; // flood fill

        for (int k = 0; k < 4; ++k)
            dfs(x + d[k], y + d[k + 1], g1, g2, ans);
    }

public:
    int countSubIslands(vector<vector<int>> &g1, vector<vector<int>> &g2)
    {
        m = g1.size();
        n = g1[0].size();
        int res = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                bool ans = true;
                if (g2[i][j] == 1)
                {
                    dfs(i, j, g1, g2, ans);
                    res += ans;
                }
            }
        }

        return res;
    }
};