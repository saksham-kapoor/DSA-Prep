class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int min_abs = INT_MAX;
        for (int i = 0; i < nums.size() && min_abs > abs(start - i); ++i)
        {
            if (nums[i] == target)
            {
                min_abs = min(min_abs, abs(start - i));
            }
        }
        return min_abs;
    }
};