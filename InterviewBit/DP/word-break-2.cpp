void solve(string &A, int idx, unordered_set<string> &st, string op, vector<string> &res)
{
    if (idx == A.size())
    {
        op.pop_back();
        res.push_back(op);
        return;
    }

    string wd;
    while (idx < A.size())
    {
        wd.push_back(A[idx]);
        if (st.find(wd) != st.end())
        {
            string s = op + wd + " ";
            solve(A, idx + 1, st, s, res);
        }
        ++idx;
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B)
{
    unordered_set<string> st(B.begin(), B.end());
    vector<string> res;
    string op;
    solve(A, 0, st, op, res);
    return res;
}
