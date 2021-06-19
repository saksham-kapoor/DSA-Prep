class Solution
{
    const static int MAXSIZE = 1e5 + 10;
    const static int MOD = 1e9 + 7;

    int bit[MAXSIZE] = {};

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
        while (idx <= MAXSIZE)
        {
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }

public:
    int createSortedArray(vector<int> &ins)
    {
        long cost = 0;

        for (int i = 0; i < ins.size(); ++i)
        {
            int left = read(ins[i] - 1);                  // number of elements smaller than nums[i]
            int right = read(MAXSIZE - 1) - read(ins[i]); // number of elements greater than nums[i]

            cost += min(left, right);
            update(ins[i], 1);
        }

        return cost % MOD;
    }
};