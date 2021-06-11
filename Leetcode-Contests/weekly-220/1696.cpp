class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size(), dp[n];
        dp[0] = nums[0];

        // for sliding window max
        deque<int> q;
        q.push_back(dp[0]);

        for (int i = 1; i < n; ++i)
        {
            if (i > k && q.front() == dp[i - k - 1])
                q.pop_front();
            dp[i] = q.front() + nums[i];
            while (q.size() && q.back() < dp[i])
                q.pop_back();
            q.push_back(dp[i]);
        }

        return dp[n - 1];
    }
};