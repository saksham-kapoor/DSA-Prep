// LIS / MSIS

class Solution
{
public:
    int maxHeight(vector<vector<int>> &A)
    {
        for (auto &v : A)
            sort(v.begin(), v.end());

        sort(A.begin(), A.end());

        int n = A.size();
        int dp[n];
        dp[0] = A[0][2];

        for (int i = 1; i < n; ++i)
        {
            dp[i] = 0;

            for (int j = 0; j < i; ++j)
            {
                if (A[j][0] <= A[i][0] && A[j][1] <= A[i][1] && A[j][2] <= A[i][2])
                    dp[i] = max(dp[i], dp[j]);
            }

            dp[i] += A[i][2];
        }

        return *max_element(dp, dp + n);
    }
};