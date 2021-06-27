// Check if a number is prime or not

// Brute -> O(N) Method
bool isPrime(int N)
{
    if (N == 1)
        return false;

    for (int i = 2; i < N; ++i)
        if (N % i == 0)
            return false;

    return true;
}

// Optimised -> O(sqrt(N))
// all divisors of a number occur in pairs of (a, b)
// i.e a * b = N
// 1 * 8 = 2 * 4 = 4 * 2 = 8 * 1 = 8
// pairs repeat after sqrt(N) (here-> sqrt(8) = 2.something so pairs invert after 2)
// so we simply find numbers till sqrt(N) and we can then easily find the second half of the pairs

// In other words, for a divisor pair (a, b)
// one of them lies above sqrt(N) and other lies below sqrt(N)
bool isPrime(int N)
{
    if (N == 1)
        return false;

    for (int i = 2; i * i <= N; ++i)
        if (N % i == 0)
            return false;
    return true;
}