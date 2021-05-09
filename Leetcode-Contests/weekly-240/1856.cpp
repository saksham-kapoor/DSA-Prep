class Solution
{
public:
    int maxSumMinProduct(vector<int> &A)
    {
        int n = A.size();
        vector<int> prev(n, -1), next(n, n);
        stack<int> s;

        // prev smaller element
        for (int i = 0; i < n; ++i)
        {
            while (s.size() && A[s.top()] >= A[i])
                s.pop();
            if (s.size())
                prev[i] = s.top();
            s.push(i);
        }

        // clear stack
        while (s.size())
            s.pop();

        // next smaller element
        for (int i = n - 1; i >= 0; --i)
        {
            while (s.size() && A[s.top()] >= A[i])
                s.pop();
            if (s.size())
                next[i] = s.top();
            s.push(i);
        }

        // prefix sum
        vector<long long> sum(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            sum[i + 1] = sum[i] + A[i];
        }

        long long ans = 0;
        // final calculations
        for (int i = 0; i < n; ++i)
        {
            int l = prev[i] + 1, r = next[i];
            long long val = sum[r] - sum[l];

            ans = max(ans, (long long)A[i] * val);
        }

        return ans % 1000000007;
    }
};