// Multiple Method to solve this
// DP, BFS, DFS

// TOP DOWN DP [DFS]
int m, n;
int t[151][151];

bool check(string &A, string &B, string &C, int i, int j)
{
    if (i == m && j == n)
        return true;

    if (t[i][j] != -1)
        return t[i][j];

    if (i < m && C[i + j] == A[i] && check(A, B, C, i + 1, j))
        return t[i][j] = true;

    if (j < n && C[i + j] == B[j] && check(A, B, C, i, j + 1))
        return t[i][j] = true;

    return t[i][j] = false;
}

int Solution::isInterleave(string A, string B, string C)
{
    m = A.size();
    n = B.size();
    memset(t, -1, sizeof(t));
    return check(A, B, C, 0, 0);
}

// BOTTOM UP METHOD
// SPACE OPTIMISED
class Solution
{
public:
    bool isInterleave(string A, string B, string C)
    {
        int m = A.size(), n = B.size();
        if (m + n != C.size())
            return false;

        bool dp[101];
        dp[0] = true;

        // row 0 -> string C is starting with string B
        for (int i = 1; i <= n; ++i)
            dp[i] = dp[i - 1] && C[i - 1] == B[i - 1];

        // main
        for (int i = 1; i <= m; ++i)
        {
            dp[0] = dp[0] && C[i - 1] == A[i - 1];

            for (int j = 1; j <= n; ++j)
            {
                dp[j] = dp[j] && C[i + j - 1] == A[i - 1];
                dp[j] = dp[j] || dp[j - 1] && C[i + j - 1] == B[j - 1];
            }
        }

        return dp[n];
    }
};
