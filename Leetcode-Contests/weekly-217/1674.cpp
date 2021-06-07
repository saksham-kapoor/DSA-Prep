// Extremely Beautiful Question!
// https://leetcode.com/problems/minimum-moves-to-make-array-complementary/discuss/953078/Prefix-sum-O(n-%2B-limit)-with-detailed-examples-and-pseudocode

class Solution
{
public:
    int minMoves(vector<int> &nums, int limit)
    {
        int sweep[2 * limit + 2], n = nums.size();
        memset(sweep, 0, sizeof(sweep));

        for (int i = 0; i < n / 2; ++i)
        {
            int justGood = nums[i] + nums[n - i - 1];
            int oneMoveMin = min(nums[i], nums[n - i - 1]) + 1;
            int oneMoveMax = max(nums[i], nums[n - i - 1]) + limit;

            --sweep[oneMoveMin];
            --sweep[justGood];
            ++sweep[justGood + 1];
            ++sweep[oneMoveMax + 1];
        }

        int ans = n, curr = n;

        for (int i = 2; i <= 2 * limit; ++i)
        {
            curr += sweep[i];
            ans = min(ans, curr);
        }

        return ans;
    }
};