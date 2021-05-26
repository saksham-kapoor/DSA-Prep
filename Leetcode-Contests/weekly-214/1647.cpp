// count the number of elements you want to keep
class Solution
{
public:
    int minDeletions(string s)
    {
        int keep = 0;
        array<int, 26> fz{};

        for (char i : s)
            ++fz[i - 'a'];

        sort(fz.begin(), fz.end(), greater<int>());

        keep += fz[0];

        for (int i = 1; i < fz.size() && fz[i] != 0; ++i)
        {
            fz[i] = min(fz[i], max(0, fz[i - 1] - 1));
            keep += fz[i];
        }

        return s.size() - keep;
    }
};

// count the number of elements you want to delete
class Solution
{
public:
    int minDeletions(string s)
    {
        int fz[26] = {};

        for (auto &i : s)
            fz[i - 'a']++;

        sort(fz, fz + 26, [](auto &a, auto &b) { return a > b; });

        int res = 0, curr = fz[0];

        for (int i = 1; i < 26; ++i)
        {
            if (fz[i] == 0)
                break;

            if (curr == 0)
                res += fz[i];
            else if (fz[i] >= curr)
            {
                res += fz[i] - curr + 1;
                fz[i] = --curr;
            }
            else
            {
                curr = fz[i];
            }
        }

        return res;
    }
};