class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &A)
    {
        int m = A.size(), n = A[0].size();
        int top = 0, bottom = A.size() - 1, left = 0, right = A[0].size() - 1, k = 0;
        vector<int> res(m * n);

        while (k < m * n)
        {
            for (int j = left; j <= right && k < m * n; ++j)
                res[k++] = A[top][j];
            ++top;

            for (int i = top; i <= bottom && k < m * n; ++i)
                res[k++] = A[i][right];
            --right;

            for (int j = right; j >= left && k < m * n; --j)
                res[k++] = A[bottom][j];
            --bottom;

            for (int i = bottom; i >= top && k < m * n; --i)
                res[k++] = A[i][left];
            ++left;
        }

        return res;
    }
};