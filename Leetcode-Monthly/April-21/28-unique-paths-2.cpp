class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        // unreachable case
        if (grid[m - 1][n - 1] == 1 || grid[0][0] == 1)
            return 0;

        int i, j;

        for (i = 0; i < m; ++i)
        {
            if (grid[i][0] == 1)
                break;
            grid[i][0] = 1;
        }

        for (; i < m; ++i)
            grid[i][0] = 0;

        for (j = 1; j < n; ++j)
        {
            if (grid[0][j] == 1)
                break;
            grid[0][j] = 1;
        }

        for (; j < n; ++j)
            grid[0][j] = 0;

        for (i = 1; i < m; ++i)
        {
            for (j = 1; j < n; ++j)
            {
                if (grid[i][j] == 1)
                    grid[i][j] = 0;
                else
                {
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                }
            }
        }

        // for(auto g:grid) {
        //     for(auto r:g) {
        //         cout << r << " ";
        //     }
        //     cout << "\n";
        // }

        return grid[m - 1][n - 1];
    }
};

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();

//         // unreachable case
//         if(grid[m - 1][n - 1] == 1) return 0;

//         // create dp matrix
//         vector<vector<int>> t(m, vector<int>(n, 0));

//         for(int i = 0; i < m; ++i) {
//             if(grid[i][0] == 1) break;
//             t[i][0] = 1;
//         }

//         for(int j = 0; j < n; ++j) {
//             if(grid[0][j] == 1) break;
//             t[0][j] = 1;
//         }

//         for(int i = 1; i < m; ++i) {
//             for(int j = 1; j < n; ++j) {
//                 if(grid[i][j] == 1) t[i][j] = 0;
//                 else {
//                     t[i][j] = t[i-1][j] + t[i][j-1];
//                 }
//             }
//         }

//         return t[m-1][n-1];
//     }
// };
