// O(N) approach

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int res = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= k)
                continue;

            int target = k - nums[i];

            if (mp.find(target) != mp.end())
            {
                res++;
                if (--mp[target] == 0)
                    mp.erase(target);
            }
            else
            {
                mp[nums[i]]++;
            }
        }

        return res;
    }
};