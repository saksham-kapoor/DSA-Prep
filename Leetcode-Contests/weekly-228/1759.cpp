class Solution
{
public:
    int countHomogenous(string s)
    {
        int idx = 0, n = s.size(), mod = 1e9 + 7;
        long res = 0;

        while (idx < n)
        {
            long cnt = 1;

            while (idx + 1 < n && s[idx] == s[idx + 1])
                ++cnt, ++idx;

            res += cnt * (cnt + 1) / 2;
            ++idx;
        }
        return res % mod;
    }
};