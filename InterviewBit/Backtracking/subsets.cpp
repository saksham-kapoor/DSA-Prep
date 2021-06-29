void solve(vector<int> &A, int idx, vector<vector<int>> &res, vector<int> &op)
{
    if (idx == A.size())
    {
        res.push_back(op);
        return;
    }

    // don't take
    solve(A, idx + 1, res, op);

    // take
    op.push_back(A[idx]);
    solve(A, idx + 1, res, op);
    op.pop_back();
}

vector<vector<int>> Solution::subsets(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> op;
    solve(A, 0, res, op);
    sort(res.begin(), res.end());
    return res;
}
