/*

Explanation - Can buy and sell stock infinite no. of times

    Example - 
    1 5 4 3 2 6 1
    . .
            . .
    
    observation - we buy and sell whenever p[i] - p[i-1] > 0
    5 - 1 = 4
    6 - 2 = 4
    profit = 4 + 4 = 8

    Simple, O(N) solution

*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        for (int i = 1; i < prices.size(); ++i)
            profit += max(0, prices[i] - prices[i - 1]);

        return profit;
    }
};