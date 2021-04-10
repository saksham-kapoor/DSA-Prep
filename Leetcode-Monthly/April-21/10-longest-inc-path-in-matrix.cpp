// FAST SOLUTION
class Solution
{
    int longestPath, m, n;
    vector<vector<int>> t, mtx;

    void solve(int i, int j)
    {
        int curr = mtx[i][j];

        int l1, l2, l3, l4;
        l1 = l2 = l3 = l4 = 1;

        if (i + 1 < m && mtx[i + 1][j] > curr)
        {
            // down
            if (t[i + 1][j] == -1)
                solve(i + 1, j);
            l1 = t[i + 1][j] + 1;
        }
        if (i - 1 >= 0 && mtx[i - 1][j] > curr)
        {
            // up
            if (t[i - 1][j] == -1)
                solve(i - 1, j);
            l2 = t[i - 1][j] + 1;
        }
        if (j + 1 < n && mtx[i][j + 1] > curr)
        {
            // right
            if (t[i][j + 1] == -1)
                solve(i, j + 1);
            l3 = t[i][j + 1] + 1;
        }
        if (j - 1 >= 0 && mtx[i][j - 1] > curr)
        {
            // left
            if (t[i][j - 1] == -1)
                solve(i, j - 1);
            l4 = t[i][j - 1] + 1;
        }

        t[i][j] = max(l1, max(l2, max(l3, l4)));
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        n = matrix[0].size();

        if (m == 1 && n == 1)
            return 1;

        longestPath = 1;
        t.resize(m, vector<int>(n, -1));
        mtx = matrix;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (t[i][j] == -1)
                {
                    solve(i, j);
                    longestPath = max(longestPath, t[i][j]);
                }
            }
        }

        return longestPath;
    }
};

// SLOW SOLUTION
class Solution
{
    int longestPath, m, n;
    vector<vector<int>> t;

    void solve(vector<vector<int>> matrix, int i, int j, int length)
    {

        length += 1;
        longestPath = max(longestPath, length);

        int curr = matrix[i][j];

        if (i + 1 < m && matrix[i + 1][j] > curr)
        {
            // down
            solve(matrix, i + 1, j, length);
        }
        if (i - 1 >= 0 && matrix[i - 1][j] > curr)
        {
            // up
            solve(matrix, i - 1, j, length);
        }
        if (j + 1 < n && matrix[i][j + 1] > curr)
        {
            // right
            solve(matrix, i, j + 1, length);
        }
        if (j - 1 >= 0 && matrix[i][j - 1] > curr)
        {
            // left
            solve(matrix, i, j - 1, length);
        }
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        n = matrix[0].size();

        if (m == 1 && n == 1)
            return 1;

        longestPath = 1;
        t.resize(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                solve(matrix, i, j, 0);
            }
        }

        return longestPath;
    }
};