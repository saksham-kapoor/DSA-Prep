// Get all prime numbers from [0, N] in O(Nlog(logN)) time ----> O(N) roughly
// O(N) extra space, where isPrime[i] = true if i is true, else false

int isPrime[10001] = {1}; // initially all numbers are marked as prime

void sieve()
{
    int MAXN = 10000;
    isPrime[1] = isPrime[0] = false; // 1 is marked as composite (basically, 1 is not prime)

    for (int i = 2; i * i <= MAX; ++i)
    {
        if (isPrime[2] == true)
        {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
}