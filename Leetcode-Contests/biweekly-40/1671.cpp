// LIS
// IMPORTANT

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &A)
    {
        int n = A.size();
        int a[n], b[n];

        vector<int> v;

        // for increasing subsequence
        for (int i = 0; i < n; ++i)
        {
            int x = A[i];
            auto it = lower_bound(v.begin(), v.end(), x);
            a[i] = it - v.begin();

            if (it != v.end())
                *it = x;
            else
                v.push_back(x);
        }

        v.clear();
        // for dec subsequence
        for (int i = n - 1; i >= 0; --i)
        {
            int x = A[i];
            auto it = lower_bound(v.begin(), v.end(), x);
            b[i] = it - v.begin();

            if (it != v.end())
                *it = x;
            else
                v.push_back(x);
        }

        // main calculation
        int res = 0;

        for (int i = 1; i < n; ++i)
        {
            if (a[i] && b[i])
                res = max(res, a[i] + b[i] + 1);
        }

        return n - res;
    }
};