class Solution
{
    const static int SIZE = 2e4 + 10;
    int bit[SIZE] = {};

    int read(int idx)
    {
        int sum = 0;
        while (idx > 0)
        {
            sum += bit[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    void update(int idx, int val)
    {
        while (idx < SIZE)
        {
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> res(nums.size(), 0);
        int smallest = *min_element(nums.begin(), nums.end());

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            res[i] = read(nums[i] - smallest);
            update(nums[i] - smallest + 1, 1);
        }

        return res;
    }
};