/*

Method 1 -> O(N^2)
            calculate all profits, return maxProfit

Method 2 -> Create profit_loss array
            i.e an array of size n-1 where p[i] = a[i+1] - a[i]
            now apply Kadane's algorithm

Method 3 -> Similar to Method 2, but instead of using an extra O(N) space,
            We apply kadane's algorithm directly on the array like so -

            curr_best = overall_best = a[1] - a[0]

            i = 2 to n
            curr_best = max(curr_best + a[i] - a[i-1], a[i] - a[i-1]);
            overall_best = max(overall_best, curr_best);

Method 4 -> Simplest and Fastest Method

            keep track in the min element
            and calculate profit in each iteration

            minPrice = INT_MAX, maxProfit = 0
            for(auto i:prices)
                minPrice = min(minPrice, i)
                maxProfit = max(maxProfit, i-minPrice)

            example
            7 1 5 3 6 2

            maxProfit = 1 - 6
                      = minElement - maxElement towards the right of minElement

*/

// Method 4
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX, maxProfit = INT_MIN;
        for (int i = 0; i < prices.size(); ++i)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

// Method 3
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;

        int curr_best, overall_best;
        overall_best = curr_best = prices[1] - prices[0];

        for (int i = 2; i < prices.size(); ++i)
        {
            int p_n_l = prices[i] - prices[i - 1];

            if (curr_best + p_n_l < p_n_l)
                curr_best = p_n_l;
            else
                curr_best = curr_best + p_n_l;

            overall_best = max(overall_best, curr_best);
        }

        if (overall_best < 0)
            return 0;
        return overall_best;
    }
};