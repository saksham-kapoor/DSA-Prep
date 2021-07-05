class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // lps lookup table
        int lps[(int)s.size()], k = 0;
        lps[0] = 0;

        for (int j = 1; j < s.size(); ++j)
        {
            while (k > 0 && s[j] != s[k])
                k = lps[k - 1];

            if (s[k] == s[j])
                ++k;

            lps[j] = k;
        }

        string repeated = s.substr(lps[(int)s.size() - 1]);

        if (s.size() == repeated.size())
            return false;

        string res = "";

        while (res.size() < s.size())
            res += repeated;

        return res == s;
    }
};