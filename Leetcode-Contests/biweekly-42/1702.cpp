// SHEEER ELEGANCE
// IF THERE ANY ZEROS, THEY ALL WILL COMBINE AT THE LOCATION OF THE FIRST OCCURENCE OF 0 AND SHIFT ALL ONES AT THE BACK
// THEN 000000 WILL TURN TO 111110

class Solution
{
public:
    string maximumBinaryString(string s)
    {
        int n = s.size(), cnt[2] = {}, pos = -1;

        for (int i = 0; i < n; ++i)
            if (s[i] == '0')
                pos = cnt[0] == 0 ? i : pos, ++cnt[0], s[i] = '1';
            else
                ++cnt[1];

        // turning 0000 to 1110 [in reality : turning 1111 to 1110]
        if (pos != -1)
            s[pos + cnt[0] - 1] = '0';

        return s;
    }
};