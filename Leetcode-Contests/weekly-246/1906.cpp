// ALWAYS DOUBLE CHECK CONSTRAINTS

class Solution
{
    int dp[100002][101] = {};

public:
    vector<int> minDifference(vector<int> &A, vector<vector<int>> &q)
    {
        int n = A.size(), m = q.size();

        for (int i = 0; i < n; ++i)
        {
            ++dp[i + 1][A[i]];

            for (int j = 1; j <= 100; ++j)
                dp[i + 1][j] += dp[i][j];
        }

        // Other way for calculating prefix
        // for(int i = 1; i <= 100; ++i)
        //     for(int j = 1; j <= n; ++j)
        //         dp[j][i] += dp[j - 1][i];

        vector<int> res(m);
        for (int i = 0; i < m; ++i)
        {
            int l = q[i][0], r = q[i][1], prev = -1, ans = INT_MAX;

            for (int k = 1; k <= 100; ++k)
            {
                if (dp[l][k] != dp[r + 1][k])
                {
                    if (prev == -1)
                        prev = k;
                    else
                    {
                        ans = min(ans, k - prev);
                        prev = k;
                    }
                }
            }

            res[i] = ans == INT_MAX ? -1 : ans;
        }

        return res;
    }
};