// 2 tricks
// 1. use '0l' instead of '0' in accumulate as sum may be 'long'
// 2. if((k -= c[i]) < 0)

class Solution
{
public:
    int chalkReplacer(vector<int> &c, long k)
    {
        long sum = accumulate(c.begin(), c.end(), 0l);

        k %= sum;

        for (int i = 0; i < c.size(); ++i)
            if ((k -= c[i]) < 0)
                return i;

        return 0;
    }
};