class Solution
{
public:
    int lengthOfLongestSubstring(string S)
    {
        int maxLength = 0, i = 0, j = 0;
        int v[128];
        memset(v, -1, sizeof(v));

        for (i = 0; i < S.size(); ++i)
        {
            if (v[S[i]] != -1)
            {
                j = max(j, v[S[i]] + 1);
            }
            v[S[i]] = i;
            maxLength = max(maxLength, i - j + 1);
        }

        return maxLength;
    }
};