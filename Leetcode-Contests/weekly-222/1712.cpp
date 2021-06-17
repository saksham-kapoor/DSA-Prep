// O(N) METHOD
// EXTREMELY ELEGANT
class Solution
{
    const static int MOD = 1e9 + 7;

public:
    int waysToSplit(vector<int> &A)
    {
        partial_sum(A.begin(), A.end(), A.begin());
        int n = A.size(), j = 1, k = 1;
        long res = 0;

        for (int i = 0; i < n; ++i)
        {
            j = max(j, i + 1);
            while (j < n - 1 && A[j] < 2 * A[i])
                ++j;

            if (j == n - 1)
                break;

            k = max(j, k);
            while (k < n - 1 && 2 * A[k] <= A[n - 1] + A[i])
                ++k;

            res += k - j;
        }

        return res % MOD;
    }
};

// O(NLOGN) METHOD
// BEAUTIFUL

class Solution
{
    const static int MOD = 1e9 + 7, ep = 1e-5;
    int n;
    long ways(int prefix[], int idx, int mx)
    {
        int mn = ceil((double)prefix[idx] / 2 - ep);
        int lower = prefix[idx] - mx, upper = prefix[idx] - mn, ii, jj;

        ii = lower_bound(prefix, prefix + n, lower) - prefix;
        jj = min(idx - 1, (int)(upper_bound(prefix, prefix + n, upper) - prefix - 1));

        return jj - ii + 1;
    }

public:
    int waysToSplit(vector<int> &nums)
    {
        n = nums.size();
        int prefix[n];
        partial_sum(nums.begin(), nums.end(), prefix);

        long res = 0;
        int mx = prefix[n - 1], mn = ceil((double)mx / 3 - ep);

        for (int i = n - 2; i >= 1; --i)
            if (prefix[n - 1] - prefix[i] >= mn)
                res += ways(prefix, i, prefix[n - 1] - prefix[i]);

        return (res % MOD);
    }
};