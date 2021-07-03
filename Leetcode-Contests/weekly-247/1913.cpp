// ans = max * secondmax - min * secondmin

// O(n) solution
class Solution
{
public:
    int maxProductDifference(vector<int> &A)
    {
        int max1, max2, min1, min2;
        max1 = max2 = INT_MIN, min1 = min2 = INT_MAX;

        for (auto &i : A)
        {
            if (i > max1 || i > max2)
            {
                max2 = min(max1, i);
                max1 = max(max1, i);
            }

            if (i < min1 || i < min2)
            {
                min2 = max(min1, i);
                min1 = min(min1, i);
            }
        }

        return max1 * max2 - min1 * min2;
    }
};

// Simple O(NLogN) solution
class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return (nums[nums.size() - 2] * nums[nums.size() - 1]) - (nums[0] * nums[1]);
    }
};