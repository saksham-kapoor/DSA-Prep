// Extremely Fast Top Down DP
class Solution
{
    const static int MOD = 1e9 + 7;
    vector<array<int, 26>> fz;
    vector<vector<int>> t;
    int max_n, max_len;
    string tar;

    int solve(int i, int j)
    {
        if (j == max_len)
            return 1;

        if (max_n - i < max_len - j)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        int ans = 0;

        // not taken
        ans = (ans + solve(i + 1, j)) % MOD;

        // take
        int ways = fz[i][tar[j] - 'a'];

        if (ways != 0)
        {
            ans = (ans + (long long)ways * solve(i + 1, j + 1)) % MOD;
        }

        return t[i][j] = ans;
    }

public:
    int numWays(vector<string> &words, string target)
    {
        int n = words[0].size();
        int len = target.size();

        max_n = n;
        max_len = len;
        tar = target;

        fz.resize(n, array<int, 26>{});

        for (int i = 0; i < (int)words.size(); ++i)
            for (int j = 0; j < n; ++j)
                ++fz[j][words[i][j] - 'a'];

        t.resize(n, vector<int>(len, -1));

        return solve(0, 0);
    }
};