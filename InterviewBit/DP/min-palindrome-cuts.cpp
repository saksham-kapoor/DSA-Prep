// Gap strategy to mark all palindromic substrings in O(N^2) time
// Suffix Strategy to solve the main question

int Solution::minCut(string A)
{
    int n = A.size();

    // make isP table
    bool dp[n][n];
    for (int g = 0; g < n; ++g)
    {
        for (int l = 0, r = g; r < n; ++l, ++r)
        {
            if (g == 0)
                dp[l][r] = true;
            else if (g == 1)
                dp[l][r] = A[l] == A[r];
            else
                dp[l][r] = A[l] == A[r] && dp[l + 1][r - 1];
        }
    }

    // suffix method
    int dp2[n];
    dp2[0] = 0;
    dp2[1] = dp[0][1] ? 0 : 1;

    for (int i = 2; i < n; ++i)
    {
        if (dp[0][i])
            dp2[i] = 0;
        else
        {
            dp2[i] = 1 + dp2[i - 1];
            int j = i - 1;
            while (j > 0)
            {
                if (dp[j][i])
                    dp2[i] = min(dp2[i], 1 + dp2[j - 1]);
                --j;
            }
        }
    }

    return dp2[n - 1];
}
