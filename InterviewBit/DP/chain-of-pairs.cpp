// checkout most optimal solution -> https://leetcode.com/problems/maximum-length-of-pair-chain/discuss/225801/Proof-of-the-greedy-solution

// O(n^2) LIS
int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size(), dp[n];
    dp[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        dp[i] = 1;

        for (int j = 0; j < i; ++j)
            if (A[j][1] < A[i][0])
                dp[i] = max(dp[i], 1 + dp[j]);
    }

    return *max_element(dp, dp + n);
}
