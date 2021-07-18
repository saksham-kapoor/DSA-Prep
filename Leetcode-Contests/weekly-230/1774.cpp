// Straightforward backtracking

class Solution
{
    int res, min_abs = INT_MAX;

    void solve(vector<int> &A, int idx, int curr, int target)
    {
        if (idx == A.size())
        {
            if (abs(curr - target) < min_abs)
                res = curr, min_abs = abs(curr - target);
            else if (abs(curr - target) == min_abs)
                res = min(res, curr);
            return;
        }

        // take 0 from this
        solve(A, idx + 1, curr, target);
        // take 1 from this
        solve(A, idx + 1, curr + A[idx], target);
        // take 2 from this
        solve(A, idx + 1, curr + 2 * A[idx], target);
    }

public:
    int closestCost(vector<int> &bc, vector<int> &tc, int target)
    {
        for (int i = 0; i < bc.size(); ++i)
            solve(tc, 0, bc[i], target);

        return res;
    }
};