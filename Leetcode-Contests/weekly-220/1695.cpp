// FIND MAX SUM SUBARRAY WITH UNIQUE ELEMENTS
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int prefix[n + 1];
        prefix[0] = 0;
        partial_sum(nums.begin(), nums.end(), prefix + 1);

        int res = 0, start = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i)
        {
            auto it = mp.find(nums[i]);
            if (it != mp.end() && it->second >= start)
            {
                start = it->second + 1;
            }

            res = max(res, prefix[i + 1] - prefix[start]);
            mp[nums[i]] = i;
        }

        return res;
    }
};