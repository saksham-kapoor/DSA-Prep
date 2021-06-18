class Solution
{
    int k, n;

    bool solve(int idx, vector<int> &op, int mask)
    {
        if (idx == op.size())
            return true;

        if (op[idx] != 0)
            return solve(idx + 1, op, mask);

        for (int i = k; i >= 1; --i)
        {
            if ((mask & (1 << i)) != 0)
                continue; // used
            if (i != 1 && (idx + i >= n || op[idx + i] != 0))
                continue; // exceed or no vacancy

            // choose
            op[idx] = i;
            if (i != 1)
                op[idx + i] = i;

            // explore
            if (solve(idx + 1, op, mask | (1 << i)))
                return true;

            // unchoose
            op[idx] = 0;
            if (i != 1)
                op[idx + i] = 0;
        }

        return false;
    }

public:
    vector<int> constructDistancedSequence(int k)
    {
        this->k = k;
        vector<int> op(2 * k - 1, 0);
        n = op.size();

        solve(0, op, 0);
        return op;
    }
};