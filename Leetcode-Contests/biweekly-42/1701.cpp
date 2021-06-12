class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &cust)
    {
        int n = cust.size(), t = 0;
        double wt = 0;

        for (int i = 0; i < n; ++i)
        {
            t = max(t, cust[i][0]); // start cooking
            t += cust[i][1];        // end
            wt += t - cust[i][0];
        }

        return wt / n;
    }
};