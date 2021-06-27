// simple method (used for non frequent calls), use dp if we know range for n, r
int nCr(int n, int r)
{
    int res = 1;
    for (int i = 1; i < r; ++i)
    {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

// dp method --> SAME AS PASCAL'S TRIANGLE
int choose[N][R];

for (int i = 0; i <= N; ++i)
    choose[i][0] = 1;

for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= min(N, R); ++j)
        choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];

return choose[n][r];