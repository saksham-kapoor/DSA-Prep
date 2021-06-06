// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/discuss/1253967/C%2B%2B-O(N)-Time-or-O(1)-Space-or-Intuitive

class Solution
{
public:
    int minFlips(string s)
    {
        int n = s.size();
        array<array<int, 2>, 2> fz = {};

        for (int i = 0; i < n; ++i)
        {
            fz[i % 2][s[i] - '0']++;
        }

        int res = INT_MAX;

        if (n % 2 == 0)
            return min(fz[0][0] + fz[1][1], fz[0][1] + fz[1][0]);

        for (int i = 0; i < n; ++i)
        {
            swap(fz[0][0], fz[1][0]);
            swap(fz[0][1], fz[1][1]);

            if (s[i] == '0')
            {
                if (fz[1][0] != 0)
                {
                    fz[0][0]++;
                    fz[1][0]--;
                }
            }
            else
            {
                if (fz[1][1] != 0)
                {
                    fz[0][1]++;
                    fz[1][1]--;
                }
            }

            res = min(res, min(fz[0][0] + fz[1][1], fz[0][1] + fz[1][0]));
        }

        return res;
    }
};