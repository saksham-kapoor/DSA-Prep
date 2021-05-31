class Solution
{
public:
    string maxValue(string n, int x)
    {
        bool is_neg = n[0] == '-';
        int len = n.size();

        for (int i = 0; i < len; ++i)
        {
            if ((is_neg && i != 0 && x < n[i] - '0') || (!is_neg && x > n[i] - '0'))
            {
                n.insert(n.begin() + i, x + '0');
                return n;
            }
        }

        n.insert(n.end(), x + '0');
        return n;
    }
};