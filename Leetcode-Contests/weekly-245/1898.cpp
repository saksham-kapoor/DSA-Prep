// BINARY SEARCH PROBLEM!

class Solution
{
    bitset<100000> cannot_use;

    bool check(string &s, string &p, vector<int> &r, int k)
    {
        cannot_use = 0;

        for (int i = 0; i < k; ++i)
            cannot_use[r[i]] = true;

        int i = 0, j = 0;
        for (int i = 0; i < s.size() && j < p.size(); ++i)
        {
            if (cannot_use[i] == true)
                continue;
            if (s[i] == p[j])
                ++j;
        }

        if (j == p.size())
            return true;

        return false;
    }

public:
    int maximumRemovals(string s, string p, vector<int> &r)
    {
        int start = 0, end = r.size(), res = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (check(s, p, r, mid) == true)
            {
                res = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return res;
    }
};