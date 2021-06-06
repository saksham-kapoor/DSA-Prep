// ONE PASS FINAL SOLUTION
// O(N) TIME, O(1) SPACE
class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 0);

        int left = 0, right = 0;

        for (int i = 1; i < n; ++i)
        {
            left = i * (nums[i] - nums[i - 1]) + left;
            right = i * (nums[n - i] - nums[n - i - 1]) + right;
            res[i] += left;
            res[n - i - 1] += right;
        }

        return res;
    }
};

// TWO PASS SOLUTION
// SAME CONCEPT
class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 0);

        int left = 0, right = 0;

        // left
        for (int i = 1; i < n; ++i)
        {
            left = i * (nums[i] - nums[i - 1]) + left;
            res[i] = left;
        }

        // right
        for (int i = n - 2; i >= 0; --i)
        {
            right = (n - i - 1) * (nums[i + 1] - nums[i]) + right;
            res[i] += right;
        }

        return res;
    }
};

// THREE PASS SOLUTION
// ORIGINAL IDEA
class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        int left[n], right[n];

        left[0] = 0;
        left[1] = nums[1] - nums[0];

        // left
        for (int i = 2; i < n; ++i)
        {
            left[i] = i * (nums[i] - nums[i - 1]) + left[i - 1];
        }

        right[n - 1] = 0;
        right[n - 2] = nums[n - 1] - nums[n - 2];

        // right
        for (int i = n - 3; i >= 0; --i)
        {
            right[i] = (n - i - 1) * (nums[i + 1] - nums[i]) + right[i + 1];
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i)
        {
            res[i] = left[i] + right[i];
        }
        return res;
    }
};