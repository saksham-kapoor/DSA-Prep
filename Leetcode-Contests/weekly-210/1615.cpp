class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        int deg[101] = {};
        int adj[101][101] = {};

        for (auto &r : roads)
        {
            int from = r[0], to = r[1];
            adj[from][to] = 1;
            adj[to][from] = 1;
            deg[from]++;
            deg[to]++;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                ans = max(ans, deg[i] + deg[j] - adj[i][j]);
            }
        }

        return ans;
    }
};