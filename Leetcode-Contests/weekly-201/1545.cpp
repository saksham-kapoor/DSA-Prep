// Recursive
class Solution
{
    string generate(int n)
    {
        if (n == 1)
            return "0";

        string s = generate(n - 1);
        s += "1";

        for (int i = s.size() - 2; i >= 0; --i)
            s.push_back(s[i] == '0' ? '1' : '0');

        return s;
    }

public:
    char findKthBit(int n, int k)
    {
        return generate(n)[k - 1];
    }
};