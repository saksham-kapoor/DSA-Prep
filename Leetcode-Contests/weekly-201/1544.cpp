// Use string as stack
// O(n)

class Solution
{
public:
    string makeGood(string s)
    {
        string res = "";

        for (int i = 0; i < s.size(); ++i)
        {
            if (res.size() && (res.back() == s[i] - 32 || res.back() == s[i] + 32))
                res.pop_back();
            else
                res.push_back(s[i]);
        }

        return res;
    }
};