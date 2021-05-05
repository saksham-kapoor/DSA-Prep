class Solution
{
    int m, n;
    vector<vector<int>> dir;

    bool solve(vector<vector<char>> &grid, int i, int j, int pi, int pj, char curr_char)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        if (grid[i][j] == curr_char - 32)
            return true;
        if (grid[i][j] >= 65 && grid[i][j] <= 90)
            return false;
        if (grid[i][j] != curr_char)
            return false;

        grid[i][j] = grid[i][j] - 32;
        bool ans = false;

        for (int d = 0; d < 4; ++d)
        {
            int newI = i + dir[d][0], newJ = j + dir[d][1];
            if (newI == pi && newJ == pj)
                continue;
            ans = ans || solve(grid, newI, newJ, i, j, curr_char);
        }

        return ans;
    }

public:
    bool containsCycle(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        if (m == 1 || n == 1)
            return false;

        dir.resize(4);
        dir[0] = {1, 0};
        dir[1] = {-1, 0};
        dir[2] = {0, 1};
        dir[3] = {0, -1};

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] >= 97 && grid[i][j] <= 122)
                {
                    if (solve(grid, i, j, -1, -1, grid[i][j]))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};