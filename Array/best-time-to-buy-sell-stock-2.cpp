// My Approach - Unnecessarily Complicated | O(N) time, O(1) space
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(), max_p = 0, temp_p = 0, min_buy = INT_MAX, p;

        for (int i = 0; i < n; i++)
        {
            min_buy = min(min_buy, prices[i]);
            p = prices[i] - min_buy;

            if (p < temp_p)
            {
                max_p += temp_p;
                min_buy = prices[i];
                temp_p = 0;
            }
            else
            {
                temp_p = p;
            }
        }
        max_p += temp_p;
        return max_p;
    }
};

// Other Approach - Extremely Easy | O(N) time, O(1) space
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(), max_profit = 0;

        for (int i = 1; i < n; i++)
            if (prices[i] > prices[i - 1])
                max_profit += prices[i] - prices[i - 1];

        return max_profit;
    }
};
