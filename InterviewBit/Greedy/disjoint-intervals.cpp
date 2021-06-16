int Solution::solve(vector<vector<int>> &A)
{
    sort(A.begin(), A.end(), [](auto &a, auto &b)
         { return a[1] < b[1]; });
    int last_start = A[0][0], last_end = A[0][1], disjoint = 1;

    for (int i = 1; i < A.size(); ++i)
    {
        int start = A[i][0], end = A[i][1];

        if (start > last_end)
        {
            ++disjoint;
            last_end = end;
        }
    }

    return disjoint;
}
