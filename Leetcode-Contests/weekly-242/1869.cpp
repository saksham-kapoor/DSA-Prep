class Solution
{
public:
    bool checkZeroOnes(string s)
    {
        int mx1 = 0, mx0 = 0, _1 = 0, _0 = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '1')
            {
                _0 = 0;
                ++_1;
                mx1 = max(mx1, _1);
            }
            else
            {
                _1 = 0;
                ++_0;
                mx0 = max(mx0, _0);
            }
        }

        if (mx1 > mx0)
            return true;
        return false;
    }
};