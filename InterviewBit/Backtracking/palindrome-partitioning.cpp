bool dp[20][20];

void solve(string A, int start, vector<string> &op, vector<vector<string>> &res)
{
    if (start == A.size())
    {
        res.push_back(op);
        return;
    }

    string wd;
    for (int i = start; i < A.size(); ++i)
    {
        wd.push_back(A[i]);
        if (dp[start][i])
        {
            op.push_back(wd);
            solve(A, i + 1, op, res);
            op.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string A)
{
    int n = A.size();

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

    vector<vector<string>> res;
    vector<string> op;
    solve(A, 0, op, res);
    return res;
}
