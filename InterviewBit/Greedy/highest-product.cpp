int Solution::maxp3(vector<int> &A)
{
    sort(A.begin(), A.end());

    int p = 0, n = 0, z = 0;
    int i = A.size() - 1;

    while (i >= 0 && A[i] >= 0)
        if (A[i] == 0)
            ++z, --i;
        else
            ++p, --i;

    n = A.size() - p - z; // negative nos

    int maxN = n >= 2 ? A[0] * A[1] : -1;

    if (p == 0)
    {
        if (z)
            return 0;
        return A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];
    }

    if (p == 1)
    {
        if (n >= 2)
            return A[A.size() - 1] * maxN;
        return 0;
    }

    if (p == 2)
    {
        if (n >= 2)
            return A[A.size() - 1] * maxN;
        if (z)
            return 0;
        return A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];
    }

    if (p == 3)
    {
        if (n >= 2)
            return max(A[A.size() - 1] * maxN, A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3]);

        return A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];
    }

    return -1; // unreachable
}
