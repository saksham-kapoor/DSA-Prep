class Solution
{
    int n;

    bool check(string &a, string &b)
    {
        int m1[26] = {}, m2[26] = {};

        for (int i = 0; i < n; ++i)
        {
            if (m1[a[i] - 'a'] == 0 && m2[b[i] - 'a'] == 0)
                m1[a[i] - 'a'] = i + 1, m2[b[i] - 'a'] = i + 1;
            else if (m1[a[i] - 'a'] != m2[b[i] - 'a'])
                return false;
        }

        return true;
    }

public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> res;
        n = pattern.size();

        for (auto &wd : words)
        {
            if (check(wd, pattern))
                res.push_back(wd);
        }

        return res;
    }
};