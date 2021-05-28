// Sliding Window Method
class Solution
{
public:
    int minOperations(vector<int> &A, int x)
    {
        // question reduces to
        // max length of subarray with sum = total_sum_of_array - x

        int n = A.size(), target = accumulate(A.begin(), A.end(), 0) - x;

        // as array contains only positive integers, we can deduce these cases
        if (target < 0)
            return -1;

        if (target == 0)
            return n;

        // now we find length of largest subarray with sum = target
        int i = 0, j = 0, res = 0, sum = 0;

        // sliding window of variable size!
        while (j < n)
        {
            sum += A[j];

            while (sum >= target && i <= j)
            {
                if (sum == target)
                    res = max(res, j - i + 1);
                sum -= A[i++];
            }
            ++j;
        }

        return res == 0 ? -1 : n - res;
    }
};

// unordered_map Method
class Solution
{
public:
    int minOperations(vector<int> &A, int x)
    {
        // question reduces to
        // max length of subarray with sum = total_sum_of_array - x

        int n = A.size(), target = accumulate(A.begin(), A.end(), 0) - x;

        // as array contains only positive integers, we can deduce these cases
        if (target < 0)
            return -1;

        if (target == 0)
            return n;

        // now we find length of largest subarray with sum = target
        unordered_map<int, int> mp;
        mp[0] = -1;
        int res = 0, sum = 0;

        for (int i = 0; i < n; ++i)
        {
            sum += A[i];

            auto it = mp.find(sum - target);

            if (it != mp.end())
            {
                res = max(res, i - it->second);
            }

            mp[sum] = i;
        }

        return res == 0 ? -1 : n - res;
    }
};