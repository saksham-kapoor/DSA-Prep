// O(n) solution using a simple fact
// i.e the len only increasing when we encounter a power of two
class Solution
{
    const static int MOD = 1e9 + 7;

public:
    int concatenatedBinary(int n)
    {
        unsigned long long res = 0;
        int len = 0;

        for (int i = 1; i <= n; ++i)
        {
            if ((i & (i - 1)) == 0)
                ++len;

            res = (res << len) % MOD;
            res = (res + i) % MOD;
        }

        return res % MOD;
    }
};

// O(n) solution using __builtin_clz(i)
class Solution
{
    const static int MOD = 1e9 + 7;

public:
    int concatenatedBinary(int n)
    {
        unsigned long long res = 0;

        for (int i = 1; i <= n; ++i)
        {
            res = (res << (32 - __builtin_clz(i))) % MOD;
            res = (res + i) % MOD;
        }

        return res % MOD;
    }
};

// O(nlogn) solution
class Solution
{
    const static int MOD = 1e9 + 7;

    int dig(int n)
    {
        int k = 0;
        while (n != 0)
        {
            n >>= 1;
            ++k;
        }
        return k;
    }

public:
    int concatenatedBinary(int n)
    {
        unsigned long long res = 0;

        for (int i = 1; i <= n; ++i)
        {
            res = (res << dig(i)) % MOD;
            res = (res + i) % MOD;
        }

        return res % MOD;
    }
};