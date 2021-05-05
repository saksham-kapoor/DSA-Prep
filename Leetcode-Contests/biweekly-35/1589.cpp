// SWEEP LINE SOLUTION
class Solution
{
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {
        long sum = 0;

        vector<int> fz(nums.size() + 1, 0);

        // SWEEP LINE
        for (auto r : requests)
        {
            ++fz[r[0]];
            --fz[r[1] + 1];
        }

        for (int i = 1; i < (int)fz.size(); ++i)
        {
            fz[i] += fz[i - 1];
        }

        sort(fz.begin(), fz.end() - 1);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)fz.size() - 1; ++i)
        {
            sum += (long)fz[i] * nums[i];
        }

        return sum % 1000000007;
    }
};

// BRUTE FORCE O(N^2) Solution
class Solution
{
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {
        long long sum = 0;
        sort(nums.rbegin(), nums.rend());

        vector<int> fz(nums.size(), 0);

        // WAY TOO MUCH TIME CONSUMING
        for (auto r : requests)
        {
            for (int i = r[0]; i <= r[1]; ++i)
                fz[i]++;
        }

        sort(fz.rbegin(), fz.rend());

        int i = 0;
        while (i < fz.size() && fz[i] != 0)
        {
            sum += ((fz[i] * nums[i]));
            ++i;
        }

        return (int)(sum % 1000000007);
    }
};