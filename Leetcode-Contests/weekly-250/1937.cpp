// Beautiful!!

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &B)
    {
        int m = B.size(), n = B[0].size();
        long long A[m][n];

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                A[i][j] = B[i][j];

        for (int i = 0; i < m - 1; ++i)
        {
            // left
            for (int j = 1; j < n; ++j)
                A[i][j] = max(A[i][j], A[i][j - 1] - 1);

            // right
            for (int j = n - 2; j >= 0; --j)
                A[i][j] = max(A[i][j], A[i][j + 1] - 1);

            // compute
            for (int j = 0; j < n; ++j)
                A[i + 1][j] += A[i][j];
        }

        return *max_element(A[m - 1], A[m - 1] + n);
    }
};