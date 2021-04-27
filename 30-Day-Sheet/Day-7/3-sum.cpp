class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &A)
    {
        int n = A.size();

        // no valid triplets
        if (n <= 2)
            return {};

        // main solution
        vector<vector<int>> ans;

        // sorting necesarry to reduce TC from O(n^3) to O(n^2)
        // as we'll be able to use the 2 pointer method
        sort(A.begin(), A.end());

        for (int i = 0; i < n - 2; ++i)
        {
            int target = -A[i];

            // if A[i] is a positive number, A[j], A[k] cannot add up to make -A[i]
            // as array is sorted
            if (target < 0)
                break;

            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = A[j] + A[k];
                if (sum < target)
                    ++j;
                else if (sum > target)
                    --k;
                else
                {
                    ans.push_back({A[i], A[j], A[k]});

                    while (j + 1 < k && A[j + 1] == A[j])
                        ++j; // ignore duplicates for j
                    while (k - 1 > j && A[k - 1] == A[k])
                        --k; // ignore duplicates for k
                    ++j;
                    --k;
                }
            }
            while (i + 1 < n - 2 && A[i + 1] == A[i])
                ++i; // ignore duplicates in outer loop
        }

        return ans;
    }
};