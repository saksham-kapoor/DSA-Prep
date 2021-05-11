class Solution
{
    bool solve(string &s, int idx, long long prev)
    {
        if (idx == s.size())
            return true;

        if (prev == 1)
        {
            for (int i = idx; i < s.size(); ++i)
            {
                if (s[i] != '0')
                    return false;
            }
            return true;
        }

        long long curr = 0;
        for (int i = idx; i < s.size(); ++i)
        {
            curr = curr * 10 + s[i] - '0';

            if (prev - curr == 1)
            {
                return solve(s, i + 1, curr);
            }

            if (curr > prev)
            {
                return false;
            }
        }

        return false;
    }

public:
    bool splitString(string s)
    {
        long long curr = 0;

        for (int i = 0; i < s.size() - 1; ++i)
        {
            curr = curr * 10 + s[i] - '0';

            if (curr >= 1e10)
                return false;

            if (solve(s, i + 1, curr))
                return true;
        }

        return false;
    }
};