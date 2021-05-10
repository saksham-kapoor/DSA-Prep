class Solution
{
public:
    int maxProductPath(vector<vector<int>> &g)
    {
        int m = g.size(), n = g[0].size();
        long long res = 0, mod = 1e9 + 7;

        long long _min[m][n], _max[m][n];

        _min[0][0] = _max[0][0] = g[0][0];

        // row 0
        for (int i = 1; i < n; ++i)
            _min[0][i] = _max[0][i] = _max[0][i - 1] * g[0][i];

        for (int i = 1; i < m; ++i)
        {
            _min[i][0] = _max[i][0] = _max[i - 1][0] * g[i][0]; // col 0

            for (int j = 1; j < n; ++j)
            {
                if (g[i][j] < 0)
                {
                    _max[i][j] = g[i][j] * min(_min[i - 1][j], _min[i][j - 1]); // neg * (min) = new max
                    _min[i][j] = g[i][j] * max(_max[i - 1][j], _max[i][j - 1]); // neg * (max) = new min
                }
                else
                {
                    _max[i][j] = g[i][j] * max(_max[i - 1][j], _max[i][j - 1]); // pos * max = new max
                    _min[i][j] = g[i][j] * min(_min[i - 1][j], _min[i][j - 1]); // pos * min = new min
                }
            }
        }

        res = _max[m - 1][n - 1];

        if (res < 0)
            return -1;

        return res % mod;
    }
};