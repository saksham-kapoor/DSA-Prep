// simple simulation problem
class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n <= 1)
            return n;

        int mx = 1;

        int nums[n + 1];
        nums[0] = 0;
        nums[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            if (i % 2 == 0)
            {
                nums[i] = nums[i / 2];
            }
            else
            {
                nums[i] = nums[i / 2] + nums[i / 2 + 1];
            }
            mx = max(mx, nums[i]);
        }

        return mx;
    }
};