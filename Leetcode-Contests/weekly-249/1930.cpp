class Solution
{
    int cnt(string &s, int letter)
    {
        int i = 0, j = s.size() - 1;
        while (s[i] != letter)
            ++i;
        while (s[j] != letter)
            --j;

        bitset<26> b(0);

        for (int k = i + 1; k < j; ++k)
            b[s[k] - 'a'] = 1;

        return b.count();
    }

public:
    int countPalindromicSubsequence(string s)
    {
        int fz[26] = {};
        int res = 0;

        for (int i = 0; i < s.size(); ++i)
            fz[s[i] - 'a']++;

        for (int i = 0; i < 26; ++i)
            if (fz[i] >= 2)
                res += cnt(s, i + 'a');

        return res;
    }
};