class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string res(n, 'a');
        k -= n;
        int j = n - 1;

        while (k != 0)
        {
            if (k <= 25)
            {
                res[j--] = 'a' + k;
                k = 0;
            }
            else
            {
                res[j--] = 'z';
                k -= 25;
            }
        }

        return res;
    }
};