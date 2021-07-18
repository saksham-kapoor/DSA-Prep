// GENIUS PROBLEM!
// Link Explanation -> https://leetcode.com/problems/decoded-string-at-index/discuss/991278/Explanation-with-pictures
// Link Code -> https://leetcode.com/problems/decoded-string-at-index/discuss/979066/Python-O(n)-solution-explained

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long len[110] = {}, len_pointer = 0, curr_len = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (isalpha(s[i]))
                len[len_pointer++] = ++curr_len;
            else
            {
                curr_len *= (s[i] - '0');
                len[len_pointer++] = curr_len;
            }
        }

        // reverse traverse lens
        for (int i = len_pointer - 1; i >= 0; --i)
        {
            k %= len[i];

            if (k == 0 && isalpha(s[i]))
                return (string) "" + s[i];
        }

        return "0"; // unreachable
    }
};