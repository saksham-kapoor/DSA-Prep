// Simple 0/1 Knapsack!

class Solution
{
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &A, int idx, int w)
    {
        if (idx == A.size() || w == 0)
            return 0;

        if (dp[idx][w] != -1)
            return dp[idx][w];

        // dont take
        int ans1 = solve(A, idx + 1, w);

        // take
        int j = idx + 1;
        while (j < A.size() && A[j][0] <= A[idx][1])
            ++j;

        int ans2 = A[idx][2] + solve(A, j, w - 1);

        return dp[idx][w] = max(ans1, ans2);
    }

public:
    int maxValue(vector<vector<int>> &A, int k)
    {
        dp.resize((int)A.size(), vector<int>(k + 1, -1));

        sort(A.begin(), A.end(), [](auto &a, auto &b)
             {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 return a[0] < b[0];
             });

        return solve(A, 0, k);
    }
};