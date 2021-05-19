class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        unordered_map<char, int> m;
        int len = -1;

        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (m.find(s[i]) != m.end())
                len = max(len, i - m[s[i]] - 1);
            else
                m[s[i]] = i;
        }

        return len;
    }
};