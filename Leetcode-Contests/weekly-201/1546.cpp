// O(n) average solution

class Solution
{
public:
    int maxNonOverlapping(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0, end = -1, res = 0, n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            int t2 = sum - target;

            auto it = mp.find(t2);
            if (it != mp.end() && it->second >= end)
            {
                ++res;
                end = i;
            }

            mp[sum] = i;
        }

        return res;
    }
};