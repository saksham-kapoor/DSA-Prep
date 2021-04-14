/*

Concept -> Once we have calculated the fz array,
           we don't care about the string as we just have to return the number of operations
           and not the final string.

           s = "aaabbbccddd"
           fz array = [3, 3, 2, 4, 0, 0, ....]

           Instead of taking account of number of deletions,
           we can take account of number of chars that we will keep.

           Sort the freq array
           [4, 3, 3, 2, 0, 0 ......]

           int keep = 0
           keep += fz[0]
           // these 4 elements would be kept in any case

           now we traverse the fz array from i = 1 till fz[i] != 0
           Main Formula
           fz[i] = min(fz[i], fz[i-1] - 1);
           fz[i] = max(0, fz[i])
           keep += fz[i]

           So we keep
           4 + 3 + 2 + 1
           = 10

           size of string -> 12

           # of deletion = 12 - 10
                         = 2

           do a dry run of "abcabcbac" to understand it better             

*/

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