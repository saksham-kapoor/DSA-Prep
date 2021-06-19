int Solution::trap(const vector<int> &A)
{
    int n = A.size();
    int prev[n], next[n];

    // prev and next
    prev[0] = A[0];
    next[n - 1] = A[n - 1];
    for (int i = 1; i < n; ++i)
    {
        prev[i] = max(prev[i - 1], A[i]);
        next[n - i - 1] = max(next[n - i], A[n - i - 1]);
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
        res += min(prev[i], next[i]) - A[i];

    return res;
}
