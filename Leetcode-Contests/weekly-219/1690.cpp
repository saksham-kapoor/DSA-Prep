// GAP2 STRATEGY
// MCM
class Solution
{
public:
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        int prefix[n + 1];
        prefix[0] = 0;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        partial_sum(stones.begin(), stones.end(), prefix + 1);

        for (int g = 1; g < n; ++g)
        {
            for (int l = 0, r = g; r < n; ++l, ++r)
            {
                if (g == 1)
                    dp[l][r] = max(stones[l], stones[r]);
                else
                {
                    int s1 = prefix[r + 1] - prefix[l + 1] - dp[l + 1][r];
                    int s2 = prefix[r] - prefix[l] - dp[l][r - 1];
                    dp[l][r] = max(s1, s2);
                }
            }
        }

        return dp[0][n - 1];
    }
};

// TOP DOWN STRATEGY
class Solution
{
    int dp[1001][1001];

    int solve(int i, int j, vector<int> &stones, int prefix[])
    {
        if (i == j)
            return 0;

        if (j == i + 1)
            return max(stones[i], stones[j]);

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        // take first stone
        ans = max(ans, prefix[j + 1] - prefix[i + 1] - solve(i + 1, j, stones, prefix));

        // take last stone
        ans = max(ans, prefix[j] - prefix[i] - solve(i, j - 1, stones, prefix));

        return dp[i][j] = ans;
    }

public:
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size(), prefix[n + 1];
        prefix[0] = 0;
        partial_sum(stones.begin(), stones.end(), prefix + 1);
        memset(dp, -1, sizeof(dp));

        return solve(0, n - 1, stones, prefix);
    }
};