// dp[i] => number of ways to reach i
// how can we reach i
// from i - 1 or i - 2
// therefore, dp[i] = dp[i - 1] + d[i - 2]

int Solution::climbStairs(int A)
{
    int dp[A + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= A; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[A];
}

// constant space solution
class Solution
{
public:
    int climbStairs(int n)
    {
        int a = 1, b = 1, c = 1;

        for (int i = 2; i <= n; ++i)
            c = b + a, a = b, b = c;

        return c;
    }
};
