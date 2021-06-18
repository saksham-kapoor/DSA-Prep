class Solution
{
    int remove(string &s, int val, char first, char second)
    {
        string st;
        int n = s.size();

        for (int i = 0; i < n; ++i)
            if (s[i] == second && st.size() && st.back() == first)
                st.pop_back();
            else
                st.push_back(s[i]);

        s = st;
        return ((n - s.size()) / 2) * val;
    }

public:
    int maximumGain(string s, int x, int y)
    {
        int res = 0;

        if (x > y)
            res += remove(s, x, 'a', 'b') + remove(s, y, 'b', 'a');
        else
            res += remove(s, y, 'b', 'a') + remove(s, x, 'a', 'b');

        return res;
    }
};