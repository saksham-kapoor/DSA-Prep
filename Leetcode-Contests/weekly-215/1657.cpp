class Solution
{
public:
    bool closeStrings(string w1, string w2)
    {
        if (w1.size() != w2.size())
            return false;

        int flag1 = 0, flag2 = 0, n = w1.size();
        array<int, 26> fz1 = {}, fz2 = {}; // empty initialization is important

        // single loop for both words are they are of same length
        for (int i = 0; i < n; ++i)
        {
            flag1 |= (1 << (w1[i] - 'a')); // bit mask to mark if a particular character is present or not
            fz1[w1[i] - 'a']++;

            flag2 |= (1 << (w2[i] - 'a'));
            fz2[w2[i] - 'a']++;
        }

        // checks if same characters are present in both words or not
        if (flag1 != flag2)
            return false;

        sort(fz1.begin(), fz1.end());
        sort(fz2.begin(), fz2.end());

        return fz1 == fz2;
    }
};