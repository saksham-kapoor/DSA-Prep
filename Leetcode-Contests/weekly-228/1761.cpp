// observation 1 : small n (2 <= n <= 400)
// can open possibility of adjacency matrix instead of adjacency list
// think if matrix is more beneficial in this case than list

// how to find trio
// mat[i][j] && mat[j][k] && mat[i][k]
// degree of i => sum(adj[i])
// degree of j => sum(adj[j])
// degree of k => sum(adj[k])

// ans = d(i) + d(j) + d(k) - 6
// -6 [accounts for common edges]

class Solution
{
public:
    int minTrioDegree(int n, vector<vector<int>> &edges)
    {
        int adj[401][401] = {}, res = INT_MAX;
        int d[401] = {};

        for (auto &e : edges)
            adj[e[0]][e[1]] = 1, adj[e[1]][e[0]] = 1, d[e[0]]++, d[e[1]]++;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (adj[i][j])
                    for (int k = 1; k <= n; ++k)
                        if (adj[i][k] && adj[j][k])
                            res = min(res, d[i] + d[j] + d[k] - 6);

        return res == INT_MAX ? -1 : res;
    }
};