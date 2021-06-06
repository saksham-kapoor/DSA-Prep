// O(n) space and time
// beautiful solution, imp!

class Solution
{
    int portsCount, maxBoxes, maxWeight, n;

    int min_trips(int i, int dp[], vector<vector<int>> &boxes)
    {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX, num = 0, wt = 0, j = i, num_p = 1, k = i;

        while (j < n && num + 1 <= maxBoxes && wt + boxes[j][1] <= maxWeight)
        {
            num += 1;
            wt += boxes[j][1];

            if (j != i && boxes[j][0] != boxes[j - 1][0])
            {
                ++num_p;
                k = j;
            }

            ++j;
        }

        ans = min(ans, num_p + 1 + min_trips(j, dp, boxes));

        if (k != i)
            ans = min(ans, 1 + (num_p - 1) + min_trips(k, dp, boxes));

        return dp[i] = ans;
    }

public:
    int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight)
    {
        this->portsCount = portsCount;
        this->maxBoxes = maxBoxes;
        this->maxWeight = maxWeight;
        n = boxes.size();

        int dp[n];
        memset(dp, -1, sizeof(dp));

        return min_trips(0, dp, boxes);
    }
};