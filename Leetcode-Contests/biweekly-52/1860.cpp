/*
    Complexity Analysis

    1 + 2 + 3 + 4 + ..... + i = i*(i + 1)/2 = m1 + m2
    TC: O(sqrt(m1 + m2))
*/

class Solution
{
public:
    vector<int> memLeak(int m1, int m2)
    {
        int i;
        for (i = 1; m1 >= i || m2 >= i; ++i)
        {
            if (m1 >= m2)
            {
                m1 -= i;
            }
            else
                m2 -= i;
        }

        return {i, m1, m2};
    }
};