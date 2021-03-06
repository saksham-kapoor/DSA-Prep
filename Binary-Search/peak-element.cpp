#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[size - 1] > nums[size - 2])
            return size - 1;

        int low = 1, high = size - 2, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                return mid;
            else if (nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};