class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int size = INT_MAX, target = 0;

        // get and store target
        for (auto &a : nums)
            target = (target + a) % p;

        if (target == 0) // if entire array is divisible by p
            return 0;

        int curr_rem = 0;
        unordered_map<int, int> rems; // will store remainders with index
        rems[0] = -1;

        for (int i = 0; i < (int)nums.size(); ++i)
        {
            curr_rem = (curr_rem + nums[i]) % p;
            int to_find = (curr_rem - target + p) % p; // most important line!

            if (rems.find(to_find) != rems.end())
                size = min(size, i - rems[to_find]);
            rems[curr_rem] = i;
        }

        if (size == nums.size())
            return -1;

        return size;
    }
};