class Solution
{
    int base = 26;
    long long mod = 1e11L + 7;
    long long power[(int)3e4 + 5];

    pair<bool, int> check(string &s, int len)
    {
        unordered_set<long long> all_hashes;

        // calculate first hash
        int i = 0, j = 0;
        long long hash = 0;
        for (; j < len; ++j)
            hash = (hash + (power[len - j - 1] * s[j]) % mod) % mod;

        all_hashes.insert(hash);

        // compute hashes for entire string
        while (j < s.size())
        {
            hash = (hash + mod - (s[i++] * power[len - 1]) % mod) % mod;
            hash = hash * base % mod;
            hash += s[j] * power[0] % mod;

            if (all_hashes.find(hash) != all_hashes.end())
                return {true, i};
            else
                all_hashes.insert(hash);
            ++j;
        }

        return {false, -1};
    }

public:
    string longestDupSubstring(string s)
    {
        int start = 1, end = s.size() - 1, res = 0;
        string ans = "";

        power[0] = 1;
        for (int i = 1; i < end; ++i)
            power[i] = (power[i - 1] * base) % mod;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            auto [works, idx] = check(s, mid);

            if (works)
            {
                ans = s.substr(idx, mid);
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return ans;
    }
};