class Solution
{
    int max_profit, res, rotations, bc, rc, profit;

public:
    int minOperationsMaxProfit(vector<int> &c, int bcost, int rcost)
    {
        if (4 * bc < rc)
            return -1;
        int n = c.size();
        profit = max_profit = rotations = 0;
        res = -1;
        bc = bcost;
        rc = rcost;

        for (int i = 0; i < n - 1; ++i)
        {
            rotations++;
            if (c[i] > 4)
            {
                c[i + 1] += c[i] - 4;
                c[i] = 4;
            }
            profit += c[i] * bc - rc;
            if (profit > max_profit)
            {
                max_profit = profit;
                res = rotations;
            }
        }

        int waiting = c[n - 1];

        while (waiting)
        {
            rotations++;
            int taken = min(4, waiting);
            waiting -= taken;
            profit += taken * bc - rc;
            if (profit > max_profit)
            {
                max_profit = profit;
                res = rotations;
            }
        }

        return res;
    }
};