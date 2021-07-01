// straight up look for patterns
// don't get intimidated by the constraints / problem level

class Solution
{
public:
    int minimumBoxes(int n)
    {
        // i = number of blocks in front of base layer
        int i = 0, sum = 0, factor = 0;

        while (true)
        {
            if (sum + i + factor > n)
                break;
            sum += i + factor;
            factor += i;
            ++i;
        }

        // place stones 1 by 1 and exit as soon as target is made
        for (int j = 0; j <= i; ++j)
            if (sum + j * (j + 1) / 2 >= n)
                return i * (i - 1) / 2 + j;

        return 0; // not reachable
    }
};