class NumArray
{
    const static int max_size = 3e4 + 10;
    int SIZE;
    int bit[max_size] = {};
    vector<int> A;

    int bit_read(int idx)
    {
        int sum = 0;
        while (idx > 0)
        {
            sum += bit[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    void bit_update(int idx, int val)
    {
        while (idx <= SIZE)
        {
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }

public:
    NumArray(vector<int> &nums)
    {
        SIZE = nums.size();
        A.resize(SIZE, 0);

        for (int i = 0; i < nums.size(); ++i)
            update(i, nums[i]);
        A = nums;
    }

    void update(int index, int val)
    {
        int x = val - A[index];
        A[index] = val;
        bit_update(index + 1, x);
    }

    int sumRange(int left, int right)
    {
        return bit_read(right + 1) - bit_read(left);
    }
};