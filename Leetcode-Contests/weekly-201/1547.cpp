// MCM

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        n = cuts.size();

        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        for (int g = 2; g < n; ++g)
        {
            for (int l = 0, r = g; r < n; ++l, ++r)
            {
                dp[l][r] = INT_MAX;
                for (int k = l + 1; k < r; ++k)
                {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r]);
                }
                dp[l][r] += cuts[r] - cuts[l];
            }
        }

        return dp[0][n - 1];
    }
};