// C++ 'FIND' FUNCTION
class Solution
{
public:
    int maxRepeating(string seq, string wd)
    {
        string curr = wd;
        int res = 0;

        while (seq.find(curr) != -1)
        {
            res++;
            curr += wd;
        }

        return res;
    }
};

// STUPID DP APPROACH
class Solution
{
public:
    int maxRepeating(string seq, string wd)
    {
        int n = seq.size(), m = wd.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = n; j >= 1; --j)
            {
                dp[j] = 0;
                if (wd[i - 1] == seq[j - 1])
                    dp[j] = 1 + dp[j - 1];
            }
        }

        int res = 0;
        for (int i = 0; i <= n; ++i)
        {
            if (dp[i] == wd.size())
            {
                int k = 0;
                ++k;
                int j = i + wd.size();
                while (j <= n && dp[j] == wd.size())
                {
                    ++k;
                    j += wd.size();
                }
                res = max(res, k);
            }
        }
        return res;
    }
};