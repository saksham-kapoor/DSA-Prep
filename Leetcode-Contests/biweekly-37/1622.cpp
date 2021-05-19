class Fancy
{
    const static int MOD = 1e9 + 7;
    unsigned long final_add, final_multiply;
    int vals[100001];
    unsigned int length = 0;

    // calculate mod inverse
    // n raised to the power k
    int inv(int n, int k)
    {
        if (k == 0)
            return 1;

        int N = ((long long)n * n) % MOD;

        if (k & 1)
            return ((long long)n * inv(N, k / 2)) % MOD;

        return inv(N, k / 2) % MOD;
    }

public:
    Fancy()
    {
        final_add = 0;
        final_multiply = 1;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    void append(int val)
    {
        unsigned long v = val;
        // modify new val so it neutralizes final_add / final_multiply
        v = (MOD + v - final_add) % MOD;
        // val = (val / final_multiply)
        v = (v * inv(final_multiply, MOD - 2)) % MOD;

        vals[length] = v;
        length++;
    }

    void addAll(int inc)
    {
        final_add = (final_add + inc) % MOD;
    }

    void multAll(int m)
    {
        final_add = (final_add * m) % MOD;
        final_multiply = (final_multiply * m) % MOD;
    }

    int getIndex(int idx)
    {
        if (idx >= length)
            return -1;

        unsigned long val = vals[idx];
        val = (val * final_multiply) % MOD;
        val = (val + final_add) % MOD;
        return val;
    }
};
