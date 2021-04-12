/*

Method 1 -> Nested loops
            for(int i=0; i<n; i++)
                sum = 0;
                for(int j=i; i<n; j++)
                    sum += a[j]
                    ans = max(ans, sum)

            time: O(N^2), space: O(1)

Method 2 -> Kadane's Algorithm
            
            MAIN CONCEPT

            curr_best = max(a[i], curr_best + a[i])

            OR -------------------------------
            
            if curr_best < 0
                curr_best = a[i]
            else
                curr_best += a[i]

            overall_best = max(overall_best, curr_best)

            easy, understand rest from code

*/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int overall_best, curr_best;
        overall_best = curr_best = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            curr_best = max(nums[i], curr_best + nums[i]);
            overall_best = max(overall_best, curr_best);
        }

        return overall_best;
    }
};