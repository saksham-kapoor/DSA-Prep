// NlogN method, extremely efficient
// SORT AND COUNT method
class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int n = nums.size(), res = 0;
        sort(nums.begin(), nums.end());

        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] != nums[i + 1])
                res += n - i - 1;
        }

        return res;
    }
};

// NlogN method, not efficient at all
class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> u;
        sort(nums.begin(), nums.end());

        u.push_back(nums[0]);

        for (int i = 1; i < n; ++i)
        {
            if (u.back() != nums[i])
            {
                u.push_back(nums[i]);
            }
        }

        int cnt = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            auto it = lower_bound(u.begin(), u.end(), nums[i]);
            cnt += it - u.begin();
        }

        return cnt;
    }
};