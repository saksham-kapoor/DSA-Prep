class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = needle.size(), h = haystack.size();

        for (int i = 0; h - i >= n; ++i)
        {
            int start = i;
            int k = start, j = 0;

            while (j < n)
            {
                if (haystack[k] != needle[j])
                    break;
                ++j, ++k;
            }

            if (j == n)
                return start;
        }

        return -1;
    }
};