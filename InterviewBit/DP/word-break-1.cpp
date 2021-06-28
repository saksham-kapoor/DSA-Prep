// solve(A, 0) -> true if 0...n-1 can be segmented
// solve(A, i) -> true if i..n-1 can be segmented

bool solve(string &A, int idx, unordered_set<string> &st, int dp[])
{
    if (idx == A.size())
        return true;

    if (dp[idx] != -1)
        return dp[idx];

    int i = idx;
    bool ans = false;
    string wd;

    while (i < A.size())
    {
        wd.push_back(A[i]);

        if (st.find(wd) != st.end() && solve(A, i + 1, st, dp))
            return dp[idx] = true;

        ++i;
    }

    return dp[idx] = false;
}

int Solution::wordBreak(string A, vector<string> &B)
{
    unordered_set<string> st(B.begin(), B.end()); // O(1) access
    int dp[A.size()];
    memset(dp, -1, sizeof(dp));
    return solve(A, 0, st, dp);
}
