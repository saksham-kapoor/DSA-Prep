// BEAUTIFUL SOLUTION
// concept
// we check the bits of each number

// for each 1 in the binary representation, we can say
// that it was introduced by the add operation!

// we check the max set bit of each number, the overall_max will be the number of mulitply operations
// as only multiply operations can shift the bits towards left!

// i>>=1 operation means -> i >>= 1 -> i = i >> 1
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int add_op = 0;
        int multiply_op = 0;

        for (auto &i : nums)
        {
            int j = 0;
            // count bits in each number and check highest set bit
            while (i)
            {
                add_op += (i & 1);
                i >>= 1;
                j++;
            }
            multiply_op = max(multiply_op, j - 1);
        }

        return add_op + multiply_op;
    }
};

// SIMPLE BRUTE
class Solution
{
    int make_div(vector<int> &nums)
    {
        int op = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] & 1)
            {
                --nums[i];
                op++;
            }
        }

        return op;
    }

    int div(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] /= 2;
        }
        return 1;
    }

    bool all_zeros(vector<int> &nums)
    {
        for (int &i : nums)
        {
            if (i != 0)
                return false;
        }
        return true;
    }

public:
    int minOperations(vector<int> &nums)
    {
        int op = 0;

        while (true)
        {
            // make all nums divisible by 2
            op += make_div(nums);
            if (all_zeros(nums))
                return op;
            op += div(nums);
        }

        return op;
    }
};