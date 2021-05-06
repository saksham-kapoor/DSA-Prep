// ONLY THREE POSSIBLE ANSWERS -> 0, 1, 2
// WE CAN DISCONNECT AN ISLAND IN MAX 2 TIMES!
/*
    1 1 1 1      1 0 1 1
    1 1 1 1  =>  0 1 1 1
    1 1 1 1      1 1 1 1
    1 1 1 1      1 1 1 1

    SO, FIRST WE CHECK IF THERE ARE TWO OR MORE ISLANDS INITIALLY -> ANS = 0
    THEN, WE KEEP REPLACING ONES WITH ZEROS AND THEN CHECK ANSWERS
    IF FIGURE IS DIVIDED INTO TWO OR MORE ISLANDS, ANS = 1
    ELSE ANS = 2

    'LAND' CONCEPT TO SAVE SPACE!!!
*/

class Solution
{
    int m, n;
    vector<int> dirx = {1, 0, -1, 0};
    vector<int> diry = {0, 1, 0, -1};

    void dfs(vector<vector<int>> &grid, int i, int j, int land)
    {
        grid[i][j] = land + 1;

        for (int k = 0; k < 4; ++k)
        {
            int newI = i + dirx[k], newJ = j + diry[k];

            if (newI < 0 || newI >= m || newJ < 0 || newJ >= n)
                continue;

            if (grid[newI][newJ] == land)
            {
                dfs(grid, newI, newJ, land);
            }
        }
    }

    int count_islands(vector<vector<int>> &grid, int land)
    {
        // check number of islands
        int num_islands = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == land)
                {
                    num_islands++;
                    dfs(grid, i, j, land);
                }
            }
        }
        return num_islands;
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();

        int land = 1;
        int num_islands = count_islands(grid, land);

        if (num_islands == 0 || num_islands >= 2)
            return 0;

        land++;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == land)
                {
                    grid[i][j] = 0;

                    num_islands = count_islands(grid, land);
                    if (num_islands == 0 || num_islands >= 2)
                        return 1;

                    land++;
                    grid[i][j] = land;
                }
            }
        }

        return 2;
    }
};