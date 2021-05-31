class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, res = INT_MIN;

        while (i < j)
            res = max(res, nums[i++] + nums[j--]);

        return res;
    }
};