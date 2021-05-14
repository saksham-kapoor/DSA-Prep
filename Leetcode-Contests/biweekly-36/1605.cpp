// O(mn) time for init
// o(m + n) time for main solution
// o(mn) space
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> A(m, vector<int>(n, 0));

        int i = 0, j = 0;
        while (i < m && j < n)
        {
            A[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= A[i][j];
            colSum[j] -= A[i][j];
            if (rowSum[i] == 0)
                ++i;
            if (colSum[j] == 0)
                ++j;
        }

        return A;
    }
};

// O(mn) time for init, O(mn) for main solution
// o(mn) space
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans[i][j] = min(colSum[j], rowSum[i]);
                colSum[j] -= ans[i][j];
                rowSum[i] -= ans[i][j];
            }
        }

        return ans;
    }
};