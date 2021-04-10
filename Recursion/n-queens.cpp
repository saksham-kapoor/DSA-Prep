// Must Read = https://leetcode.com/problems/n-queens/discuss/19808/Accepted-4ms-c%2B%2B-solution-use-backtracking-and-bitmask-easy-understand.

// Best Solution
class Solution
{
    vector<vector<string>> ans;
    vector<string> op;
    vector<int> flag;
    int size;

    void solve(int row)
    {
        if (row == size)
        {
            ans.push_back(op);
            return;
        }

        // main
        int i = row;
        for (int j = 0; j < size; j++)
        {
            if (flag[j] && flag[size + i + j] && flag[4 * size - 2 + j - i])
            {
                // select
                op[i][j] = 'Q';
                flag[j] = flag[size + i + j] = flag[4 * size - 2 + j - i] = 0;

                // go further
                solve(row + 1);

                // deselect
                op[i][j] = '.';
                flag[j] = flag[size + i + j] = flag[4 * size - 2 + j - i] = 1;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        size = n;
        vector<string> op1(n, string(n, '.'));
        op = op1;
        flag.resize(5 * n - 2, 1);

        solve(0);

        return ans;
    }
};

// Okayish Speed Solution

class Solution
{
    vector<vector<string>> ans;
    vector<string> op;
    int size;

    bool checkSafe(int x, int y)
    {

        // check vertical
        for (int i = 0; i < size; i++)
            if (op[i][y] == 'Q')
                return false;

        // check upper left diagonal
        int minXY = min(x, y);
        int i = x - minXY, j = y - minXY;
        while (i != x)
        {
            if (op[i][j] == 'Q')
                return false;
            i++;
            j++;
        }

        // check upper right diagonal
        minXY = min(x, size - 1 - y);
        i = x - minXY;
        j = y + minXY;
        while (i != x)
        {
            if (op[i][j] == 'Q')
                return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(int q, int x, int y)
    {
        op[x][y] = 'Q';
        q--;

        if (q == 0)
        {
            ans.push_back(op);
            op[x][y] = '.';
            return;
        }

        // main
        for (int i = x + 1; i < size; i++)
            for (int j = 0; j < size; j++)
                if (checkSafe(i, j))
                    solve(q, i, j);

        op[x][y] = '.';
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        size = n;
        vector<string> op1(n, string(n, '.'));
        op = op1;

        for (int i = 0; i < n; i++)
            solve(n, 0, i);

        return ans;
    }
};