// same as stone game!
// solved using gap strategy, can be done using top-down as well

#include <numeric>

int Solution::maxcoin(vector<int> &A)
{
    int n = A.size(), dp[n][n];
    int prefix[n + 1];
    prefix[0] = 0;
    partial_sum(A.begin(), A.end(), prefix + 1);

    for (int g = 0; g < n; ++g)
    {
        for (int l = 0, r = g; r < n; ++l, ++r)
        {
            if (g == 0)
                dp[l][r] = A[l];
            else if (g == 1)
                dp[l][r] = max(A[l], A[r]);
            else
            {
                dp[l][r] = max(prefix[r + 1] - prefix[l] - dp[l + 1][r], prefix[r + 1] - prefix[l] - dp[l][r - 1]);
            }
        }
    }

    return dp[0][n - 1];
}
