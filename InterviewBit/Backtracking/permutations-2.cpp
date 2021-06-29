// with duplicates

class Solution
{
    void solve(int used, vector<int> &A, vector<vector<int>> &res, vector<int> &op)
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
                // choose
                op.push_back(A[i]);
                // explore
                solve(used | (1 << i), A, res, op);
                //unchoose
                op.pop_back();
                // skip duplicates
                while (i + 1 < A.size() && A[i + 1] == A[i])
                    ++i;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &A)
    {
        sort(A.begin(), A.end());
        vector<vector<int>> res;
        vector<int> op;

        solve(0, A, res, op);

        return res;
    }
};