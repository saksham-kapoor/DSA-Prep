class Solution
{
    bool rabinKarp(string &s, string &b)
    {
        int base = 26, len = b.size();
        long long power[len], mod = 1e11L + 7;
        power[0] = 1;

        // precompute powers
        for (int i = 1; i < len; ++i)
            power[i] = (power[i - 1] * base) % mod;

        // create pattern hash
        long long phash = 0;
        for (int i = 0; i < len; ++i)
            phash = (phash + power[len - i - 1] * b[i] % mod) % mod;

        // create main substring hashes
        long long hash = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i >= len)
                hash = (hash + mod - power[len - 1] * s[i - len] % mod) % mod;

            hash = hash * base % mod;
            hash = (hash + power[0] * s[i] % mod) % mod;

            if (i >= len - 1 && phash == hash)
                return true;
        }
        return false;
    }

    void create_lps(string &pattern, int lps[])
    {
        lps[0] = 0;
        int k = 0;

        for (int j = 1; j < pattern.size(); ++j)
        {
            while (k > 0 && pattern[k] != pattern[j])
                k = lps[k - 1];

            if (pattern[j] == pattern[k])
                k++;

            lps[j] = k;
        }
    }

    bool kmp(string &text, string &pattern)
    {
        // create lps table : longest prefix suffix
        int lps[(int)pattern.size()];
        create_lps(pattern, lps);

        int j = 0; // pattern pointer

        for (int i = 0; i < text.size(); ++i)
        {
            while (j > 0 && pattern[j] != text[i])
                j = lps[j - 1];

            if (pattern[j] == text[i])
                ++j;

            if (j == pattern.size())
                return true;
        }

        return false;
    }

    bool check(string &a, string &b)
    {
        // return rabinKarp(a, b);
        return kmp(a, b);
    }

public:
    int repeatedStringMatch(string a, string b)
    {
        int res = 1;
        string A = a;
        while (a.size() < b.size())
            a += A, ++res;

        if (check(a, b))
            return res;

        a += A;
        if (check(a, b))
            return res + 1;

        return -1;
    }
};