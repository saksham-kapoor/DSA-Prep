class Solution
{
    const static int MOD = 1e9 + 7;

public:
    int numberOfSets(int n, int k)
    {
        n = n + k - 1;
        k = 2 * k;
        k = min(k, n - k);

        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= min(i, k); ++j)
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }

        return dp[n][k];
    }
};