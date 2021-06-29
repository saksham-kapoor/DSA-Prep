void solve(vector<int> &A, int used, vector<vector<int>> &res, vector<int> &op)
{
    if (used == (1 << A.size()) - 1)
    {
        res.push_back(op);
        return;
    }

    for (int i = 0; i < A.size(); ++i)
    {
        if ((used & (1 << i)) == 0)
        {
            //choose
            op.push_back(A[i]);
            // explore
            solve(A, used | (1 << i), res, op);
            // unchoose
            op.pop_back();
        }
    }
}

vector<vector<int>> Solution::permute(vector<int> &A)
{
    vector<vector<int>> res;
    vector<int> op;
    solve(A, 0, res, op);
    return res;
}
