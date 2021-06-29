#include <bitset>

void solve(int n, int r, bitset<20> &cc, bitset<20> &d1, bitset<20> &d2, vector<string> &op, vector<vector<string>> &res)
{
    if (r == n)
    {
        res.push_back(op);
        return;
    }

    for (int c = 0; c < n; ++c)
    {
        if (!cc[c] && !d1[n - 1 + r - c] && !d2[r + c])
        {
            // choose
            cc[c] = d1[n - 1 + r - c] = d2[r + c] = 1;
            op[r][c] = 'Q';
            // explore
            solve(n, r + 1, cc, d1, d2, op, res);
            // unchoose
            cc[c] = d1[n - 1 + r - c] = d2[r + c] = 0;
            op[r][c] = '.';
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n)
{
    vector<vector<string>> res;
    vector<string> op(n, string(n, '.'));
    bitset<20> cc(0), d1(0), d2(0);

    solve(n, 0, cc, d1, d2, op, res);
    return res;
}
