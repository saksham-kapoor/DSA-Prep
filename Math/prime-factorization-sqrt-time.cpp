// find prime factors of N
int N = 100;

// Brute Force Approach O(N) time
// O(N) is worst case TC, and it occurs when N is prime
void get_factors(int N)
{
    for (int i = 2; i <= N; ++i)
    {
        if (N % i == 0)
        {
            int cnt = 0;
            while (N % i == 0)
                cnt++, N /= i;

            cout << "factor: " << i << ", frequency: " << cnt << "\n";
        }
    }
}

// Optimised
// if N is composite, it must have a prime divisor <= sqrt(N)
// else N is prime
void get_factors(int N)
{
    for (int i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            int cnt = 0;
            while (N % i == 0)
                ++cnt, N /= i;
            cout << "factor: " << i << ", frequency: " << cnt << "\n";
        }
    }
    if (N > 1)
        cout << "factor: " << N << ", frequency: " << 1 << "\n";
}