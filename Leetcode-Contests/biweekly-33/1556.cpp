class Solution
{
public:
    string thousandSeparator(int n)
    {
        string op;
        int k = 0;

        while (n)
        {
            int x = n % 10;
            if (k != 0 && k % 3 == 0)
            {
                op.push_back('.');
                k = 0;
            }
            op.push_back('0' + x);
            n /= 10;
            k++;
        }

        if (op.size() == 0)
            return "0";

        reverse(op.begin(), op.end());

        return op;
    }
};