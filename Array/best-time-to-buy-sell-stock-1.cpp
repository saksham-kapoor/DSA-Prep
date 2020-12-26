// Array, DP

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(), max_profit = 0, min_buy = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            min_buy = min(min_buy, prices[i]);
            max_profit = max(max_profit, prices[i] - min_buy);
        }
        return max_profit;
    }
};