class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> fz;
        int res = 0;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            res += fz[nums[i]]++;
        }

        return res;
    }
};