// FASTER
// GREEDY -> GET THE FARTHEST REACH AT EACH POINT
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int n = (int)nums.size();
        if (n == 1)
            return true;

        int reach = 0, i = 0;

        for (; i <= reach && reach < n - 1; ++i)
            reach = max(reach, i + nums[i]);

        return (reach >= n - 1);
    }
};

// METHOD 2 -> FASTER
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int n = (int)nums.size();
        if (n == 1)
            return true;

        int target = n - 1;

        for (int i = n - 2; i >= 0; --i)
            if (i + nums[i] >= target)
                target = i;

        if (target == 0)
            return true;
        return false;
    }
};

// METHOD 1 -> SLOW
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int n = (int)nums.size();
        if (n == 1)
            return true;

        for (int i = n - 2; i >= 0; --i)
        {
            int jumps = nums[i];

            for (int j = 1; j <= jumps && j < n; ++j)
            {
                if (nums[i + j] < 0 || i + j == n - 1)
                {
                    nums[i] = -nums[i];
                    break;
                }
            }
        }

        if (nums[0] < 0)
            return true;
        return false;
    }
};