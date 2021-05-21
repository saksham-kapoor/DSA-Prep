class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int m1[128] = {}, m2[128] = {};
        int n = s.size();

        for (int i = 0; i < n; ++i)
        {
            if (m1[s[i]] == 0 && m2[t[i]] == 0)
                m1[s[i]] = i + 1, m2[t[i]] = i + 1;
            else if (m1[s[i]] != m2[t[i]])
                return false;
        }

        return true;
    }
}