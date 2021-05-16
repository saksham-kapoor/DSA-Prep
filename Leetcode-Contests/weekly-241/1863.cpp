class Solution
{
    int iterative(vector<int> &nums)
    {
        int n = nums.size();
        int num = (1 << n) - 1;

        int _xor = 0;

        for (; num >= 1; --num)
        {

            int _xor_ = 0;
            for (int i = 0; i < n; ++i)
            {
                if (num & (1 << i))
                {
                    _xor_ ^= nums[i];
                }
            }

            _xor += _xor_;
        }

        return _xor;
    }

    int count;
    void recursive(vector<int> &nums, int idx, int curr)
    {
        if (idx == nums.size())
        {
            count += curr;
            return;
        }

        // don't select nums[idx] in subset
        recursive(nums, idx + 1, curr);

        // select nums[idx] in subset
        recursive(nums, idx + 1, curr ^ nums[idx]);
    }

public:
    int subsetXORSum(vector<int> &nums)
    {
        count = 0;
        recursive(nums, 0, 0);
        return count;
        // return iterative(nums);
    }
};