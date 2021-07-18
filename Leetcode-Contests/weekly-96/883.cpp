// read questions carefully, it said it's a square matrix
// that helped us to reduce this code from 2 pass to 1 pass

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int n = grid.size(), res = 0;

        for (int i = 0; i < n; ++i)
        {
            int max_col = 0, max_row = 0;

            for (int j = 0; j < n; ++j)
            {
                res += grid[i][j] != 0;             // xy plane
                max_row = max(max_row, grid[i][j]); // xz plance
                max_col = max(max_col, grid[j][i]); // yz plane
            }

            res += max_row + max_col;
        }

        return res;
    }
};