// Keep on deleting similar ends

class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                while (i <= j && s[i] == s[j])
                    ++i;
                while (i <= j && s[j] == s[i - 1])
                    --j;
            }
            else
                break;
        }
        return j - i + 1;
    }
};