class Solution
{
    const static int MOD = 1e9 + 7;

public:
    int rearrangeSticks(int n, int k)
    {
        int t[1001][1001] = {};

        // standard cases
        t[1][1] = t[2][1] = t[2][2] = 1;

        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                // placing smallest at first position so it is visible,
                // now place remaining elements such that k - 1 elements are visible
                // and remaining array size is now i - 1
                t[i][j] = t[i - 1][j - 1];

                // place any other element [(i - 1) choices] at first position other than smallest
                // now we have i - 1 spaces, and we need k visible sticks
                t[i][j] = (t[i][j] + ((long long)(i - 1) * t[i - 1][j]) % MOD) % MOD;
            }
        }

        // recurrence relation
        // t[n][k] = t[n - 1][k - 1] + (n - 1) * t[n - 1][k];

        return t[n][k];
    }
};