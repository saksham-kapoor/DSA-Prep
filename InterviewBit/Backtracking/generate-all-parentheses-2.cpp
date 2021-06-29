void solve(int n, int open, int total_open, string &op, vector<string> &res)
{
    if (open == 0 && total_open == n)
    {
        res.push_back(op);
        return;
    }

    if (open)
    {
        op.push_back(')');
        solve(n, open - 1, total_open, op, res);
        op.pop_back();
    }

    if (total_open < n)
    {
        op.push_back('(');
        solve(n, open + 1, total_open + 1, op, res);
        op.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int A)
{
    vector<string> res;
    string op;
    solve(A, 0, 0, op, res);
    sort(res.begin(), res.end());
    return res;
}
