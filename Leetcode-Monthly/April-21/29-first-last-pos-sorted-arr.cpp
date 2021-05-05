class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // get leftmost index
        int i = 0, j = nums.size() - 1, mid, left = -1, right;

        while (i <= j)
        {
            int mid = i + ((j - i) >> 1);
            if (nums[mid] == target)
            {
                left = mid;
                j = mid - 1;
            }
            else if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }

        if (left == -1)
            return {-1, -1};

        i = 0;
        j = nums.size() - 1;

        while (i <= j)
        {
            int mid = i + ((j - i) >> 1);
            if (nums[mid] == target)
            {
                right = mid;
                i = mid + 1;
            }
            else if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }

        return {left, right};
    }
};