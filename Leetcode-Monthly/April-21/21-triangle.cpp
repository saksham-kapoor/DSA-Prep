/*
Bottom up DP
Trace it out on paper for better understanding
*/

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> t(triangle.back());

        for (int row = n - 2; row >= 0; --row)
        {
            for (int col = 0; col <= row; ++col)
            {
                t[col] = min(t[col], t[col + 1]) + triangle[row][col];
            }
        }

        return t[0];
    }
};

// Recursion + Memoization
class Solution
{
    vector<vector<int>> t;
    int solve(vector<vector<int>> &triangle, int row, int col)
    {
        if (row >= triangle.size())
            return 0;

        if (t[row][col] != -1)
            return t[row][col];

        int new_sum = triangle[row][col];
        new_sum += min(solve(triangle, row + 1, col), solve(triangle, row + 1, col + 1));
        return t[row][col] = new_sum;
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        t.resize(n, vector<int>(triangle[n - 1].size(), -1));
        solve(triangle, 0, 0);
        return t[0][0];
    }
};

// Simple Recursion Solution
class Solution
{
    int minSum;
    void solve(vector<vector<int>> &triangle, int row, int col, int sum)
    {
        if (row >= triangle.size())
        {
            minSum = min(minSum, sum);
        }
        else
        {
            sum = sum + triangle[row][col];
            solve(triangle, row + 1, col, sum);
            solve(triangle, row + 1, col + 1, sum);
        }
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int sum = 0;
        minSum = INT_MAX;
        solve(triangle, 0, 0, sum);
        return minSum;
    }
};
