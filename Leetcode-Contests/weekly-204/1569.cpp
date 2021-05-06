class Solution
{
    int MOD = 1e9 + 7;
    vector<vector<int>> pascals;

    void gen_pascals(int n)
    {
        pascals.resize(n + 1, vector<int>(n + 1, 0));
        pascals[0][0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            pascals[i][0] = 1;
            for (int j = 1; j <= i; ++j)
            {
                pascals[i][j] = ((long long)pascals[i - 1][j] + pascals[i - 1][j - 1]) % MOD;
            }
        }
    }

    int num_ways(vector<int> &nodes)
    {
        if (nodes.size() <= 2)
            return 1;

        vector<int> left, right;

        for (int i = 1; i < nodes.size(); ++i)
            if (nodes[i] < nodes[0])
                left.push_back(nodes[i]);
            else
                right.push_back(nodes[i]);

        int left_ans = num_ways(left);
        int right_ans = num_ways(right);

        return (((long long)pascals[left.size() + right.size()][left.size()] * left_ans) % MOD) * right_ans % MOD;
    }

public:
    int numOfWays(vector<int> &nums)
    {
        gen_pascals(nums.size());
        return num_ways(nums) - 1;
    }
};