// Gap strategy once again!

class Solution
{
    bool dp[2001][2001] = {};

public:
    bool checkPartitioning(string s)
    {
        int n = s.size();

        for (int g = 0; g < n; ++g)
            for (int l = 0, r = g; r < n; ++l, ++r)
                if (g == 0)
                    dp[l][r] = true;
                else if (g == 1)
                    dp[l][r] = s[l] == s[r];
                else
                    dp[l][r] = s[l] == s[r] && dp[l + 1][r - 1];

        for (int i = n - 1; i >= 2; --i)
        {
            if (dp[i][n - 1])
                for (int j = i - 1; j > 0; --j)
                    if (dp[0][j - 1] && dp[j][i - 1])
                        return true;
        }

        return false;
    }
};