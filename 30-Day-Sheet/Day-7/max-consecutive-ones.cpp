// Pretty straightforward O(N) solution
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int global_max = 0, max_so_far = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i])
                ++max_so_far;
            else
            {
                global_max = max(global_max, max_so_far);
                max_so_far = 0;
            }
        }

        return max(global_max, max_so_far);
    }
};