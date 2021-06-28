// Minimum numbers required to make a target sum

#include <numeric>

int Solution::solve(const vector<int> &A)
{
    int n = A.size(), sum = accumulate(A.begin(), A.end(), 0) / 2;
    int dp[n + 1][sum + 1];
    memset(dp, 0, sizeof(dp));

    // when n = 0
    for (int i = 1; i <= sum; ++i)
        dp[0][i] = 1e5;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= sum; ++j)
            if (A[i - 1] <= j)
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][j - A[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];

    for (int i = sum; i >= 0; --i)
        if (dp[n][i] < 100)
            return dp[n][i];

    return 0;
}