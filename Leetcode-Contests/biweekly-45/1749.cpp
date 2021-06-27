// Max prefix sum - min prefix sum
// 1 pass O(n), O(1) space
class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int curr = 0, maxp = 0, minp = 0;

        for (auto &i : nums)
        {
            curr += i;
            maxp = max(maxp, curr);
            minp = min(minp, curr);
        }

        return maxp - minp;
    }
};

// Kadane's Algorithm
// 3 pass solution
class Solution
{
    int kadane(vector<int> &A)
    {
        int curr_max = A[0], og_max = A[0];
        for (int i = 1; i < A.size(); ++i)
        {
            curr_max = max(curr_max + A[i], A[i]);
            og_max = max(og_max, curr_max);
        }
        return og_max;
    }

public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int res1 = kadane(nums);
        for (auto &i : nums)
            i = -i;
        int res2 = kadane(nums);
        return max(res1, res2);
    }
};