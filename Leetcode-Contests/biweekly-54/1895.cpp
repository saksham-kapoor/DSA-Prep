class Solution
{
public:
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), res = 0;

        int rows[52][52] = {}, cols[52][52] = {}, d1[52][52] = {}, d2[52][52] = {};

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
            {
                rows[i][j] += grid[i - 1][j - 1] + rows[i][j - 1];
                cols[i][j] += grid[i - 1][j - 1] + cols[i - 1][j];
                d1[i][j] += grid[i - 1][j - 1] + d1[i - 1][j - 1];
                d2[i][j] += grid[i - 1][j - 1] + d2[i - 1][j + 1];
            }

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = min(m - i, n - j); k > res; --k)
                {
                    int sum = d1[i + k][j + k] - d1[i - 1][j - 1];
                    bool match = sum == d2[i + k][j] - d2[i - 1][j + k + 1];
                    for (int l = 0; l <= k && match; ++l)
                    {
                        match &= sum == rows[i + l][j + k] - rows[i + l][j - 1];
                        match &= sum == cols[i + k][j + l] - cols[i - 1][j + l];
                    }
                    res = match ? k : res;
                }

        // res stores number of edges, res + 1 gives the actual length or number of vertices
        return res + 1;
    }
};