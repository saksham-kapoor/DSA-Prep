class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n);

        for (int i = 0; i < n; ++i)
        {

            int c = i; // initial column

            for (int r = 0; r < m; ++r)
            {
                if (c + grid[r][c] == n || c + grid[r][c] == -1 || grid[r][c] != grid[r][c + grid[r][c]])
                {
                    c = -1;
                    break;
                }

                c += grid[r][c];
            }

            res[i] = c;
        }

        return res;
    }
};