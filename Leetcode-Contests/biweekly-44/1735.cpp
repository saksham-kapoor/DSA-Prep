// Prerequisites
// 1. prime factorization using sieve
// 2. stars and bars
// 3. combinatorics using DP

class Solution
{
    static const int MOD = 1e9 + 7, MAX = 1e4;

    int spf[10001] = {};         // smallest prime factor
    long choose[10031][16] = {}; // nCr

    void sieve()
    {
        memset(spf, -1, sizeof(spf));

        for (int i = 2; i <= MAX; ++i)
        {
            if (spf[i] == -1)
            {
                spf[i] = i;
                for (int j = i * i; j <= MAX; j += i)
                    if (spf[j] == -1)
                        spf[j] = i;
            }
        }
    }

    void comb()
    {
        // choose 0 objects -> 1 way
        for (int i = 0; i <= 10030; ++i)
            choose[i][0] = 1;

        for (int i = 1; i <= 10030; ++i)
            for (int j = 1; j <= 15; ++j)
                choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
    }

    vector<int> get_factors(int N)
    {
        unordered_map<int, int> ffz;
        vector<int> res;

        while (N != 1)
        {
            ffz[spf[N]]++;
            N /= spf[N];
        }

        for (auto &[n, fz] : ffz)
            res.push_back(fz);

        return res;
    }

public:
    vector<int> waysToFillArray(vector<vector<int>> &qq)
    {
        // calculate prime factors of all k
        sieve();
        comb();

        vector<int> res;

        for (auto &q : qq)
        {
            int k = q[0], x = q[1];
            long ans = 1;

            vector<int> factors = get_factors(x);

            // k = number of boxes, n = number of identical objects
            for (auto &n : factors)
            {
                ans = (ans * choose[n + k - 1][n]) % MOD; // or choose[n + k - 1][k - 1]
            }

            res.push_back(ans);
        }

        return res;
    }
};