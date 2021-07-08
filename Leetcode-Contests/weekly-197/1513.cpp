class Solution
{
public:
    int numSub(string s)
    {
        long res = 0, count = 0, mod = 1e9 + 7;

        for (int i = 0; i < s.size(); ++i)
        {
            count = s[i] == '1' ? count + 1 : 0;
            res = (res + count) % mod;
        }

        return res;
    }
};

/*
    Exactly same as counting all consecutive ones and doing n * (n + 1) / 2
*/