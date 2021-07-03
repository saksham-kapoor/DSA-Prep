// O(2 * M * N) SOLUTION
// O(M + N) Extra Space
class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size(), ll = min(m, n) / 2;

        for (int l = 0; l < ll; ++l)
        {
            vector<int> v;

            for (int i = l; i < n - l - 1; ++i) // top row
                v.push_back(grid[l][i]);

            for (int i = l; i < m - l - 1; ++i) // right
                v.push_back(grid[i][n - l - 1]);

            for (int i = n - l - 1; i > l; --i) // bottom row
                v.push_back(grid[m - l - 1][i]);

            for (int i = m - l - 1; i > l; --i) // left
                v.push_back(grid[i][l]);

            // assign it back to the grid from the 'start' position
            int start = k % v.size();

            for (int i = l; i < n - l - 1; ++i) // top row
                grid[l][i] = v[start++ % v.size()];

            for (int i = l; i < m - l - 1; ++i) // right
                grid[i][n - l - 1] = v[start++ % v.size()];

            for (int i = n - l - 1; i > l; --i) // bottom row
                grid[m - l - 1][i] = v[start++ % v.size()];

            for (int i = m - l - 1; i > l; --i) // left
                grid[i][l] = v[start++ % v.size()];
        }

        return grid;
    }
};

// O(K * M * N) Solution
// O(1) Extra Space
// 4 pointer method (TBLR)
class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &A, int k)
    {
        int top = 0, bottom = A.size() - 1, left = 0, right = A[0].size() - 1;

        while (bottom > top && right > left)
        {
            int n = 2 * (bottom - top + 1) + 2 * (right - left + 1) - 4;
            int t = k % n;

            while (t--)
            {
                int temp = A[top][left];

                for (int j = left; j < right; ++j)
                    A[top][j] = A[top][j + 1];

                for (int i = top; i < bottom; ++i)
                    A[i][right] = A[i + 1][right];

                for (int j = right; j > left; --j)
                    A[bottom][j] = A[bottom][j - 1];

                for (int i = bottom; i > top; --i)
                    A[i][left] = A[i - 1][left];

                A[top + 1][left] = temp;
            }

            ++top, --bottom, ++left, --right;
        }

        return A;
    }
};