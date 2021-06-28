// catalan numbers!

long long nCr(int n, int r)
{
    long long res = 1;
    for (int i = 1; i <= r; ++i)
    {
        res *= (long long)n - i + 1;
        res /= i;
    }
    return res;
}

int Solution::numTrees(int n)
{
    return (long long)nCr(2 * n, n) / (long long)(n + 1);
}
