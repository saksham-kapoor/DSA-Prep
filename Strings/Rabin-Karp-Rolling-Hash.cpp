class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        if (n == 0)
            return 0;
        if (n > m)
            return -1;

        int base = 26; // usually base = number of unique elements
        unsigned long long power[n], mod = 1e11L + 7;
        power[0] = 1;

        // create power array
        for (int i = 1; i < n; ++i)
            power[i] = power[i - 1] * base % mod;

        // create pattern hash
        long long phash = 0;
        for (int i = 0; i < n; ++i)
            phash = (phash + power[n - i - 1] * needle[i] % mod) % mod;

        // create main string hashes
        long long hash = 0;
        for (int i = 0; i < m; ++i)
        {
            if (i >= n)
                hash = (hash + mod - power[n - 1] * haystack[i - n] % mod) % mod;

            hash = hash * base % mod;
            hash = (hash + power[0] * haystack[i] % mod) % mod;

            if (i >= n - 1 && phash == hash)
                return i - n + 1;
        }

        return -1;
    }
};