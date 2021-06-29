// elements cannot be used more than once

void solve(vector<int> &A, int idx, int target, vector<int> &op, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(op);
        return;
    }

    for (int i = idx; i < A.size(); ++i)
    {
        if (target - A[i] >= 0)
        {
            // choose, explore, unchoose
            op.push_back(A[i]);
            solve(A, i + 1, target - A[i], op, res);
            op.pop_back();

            // skip duplicates
            while (i + 1 < A.size() && A[i + 1] == A[i])
                ++i;
        }
        else
            break;
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> op;

    solve(A, 0, B, op, res);
    return res;
}
