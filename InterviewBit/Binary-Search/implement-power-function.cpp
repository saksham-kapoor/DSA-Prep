// For +ve n only

int calc(long long x, int n, int d)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return calc((x * x) % d, n / 2, d);

    return (x * calc((x * x) % d, n / 2, d)) % d;
}

int Solution::pow(int x, int n, int d)
{
    if (x == 0)
        return 0;
    int ans = calc(x, n, d);
    if (ans < 0)
        return d + ans;
    return ans;
}
