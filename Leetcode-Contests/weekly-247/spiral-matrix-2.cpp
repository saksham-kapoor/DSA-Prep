class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n));

        int top = 0, bottom = n - 1, left = 0, right = n - 1, k = 1;

        while (bottom >= top && right >= left && k <= n * n)
        {
            for (int j = left; j <= right && k <= n * n; ++j)
                res[top][j] = k++;
            ++top;

            for (int i = top; i <= bottom && k <= n * n; ++i)
                res[i][right] = k++;
            --right;

            for (int j = right; j >= left && k <= n * n; --j)
                res[bottom][j] = k++;
            --bottom;

            for (int i = bottom; i >= top && k <= n * n; --i)
                res[i][left] = k++;
            ++left;
        }

        return res;
    }
};