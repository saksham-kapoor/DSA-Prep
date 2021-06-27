int A[1000001] = {-1}; // initially entire array is initialized with -1

void sieve()
{
    int MAX = 1000000;

    for (int i = 2; i <= MAX; ++i)
    {
        if (A[i] == -1)
        {
            A[i] = i;
            for (int j = i * i; j <= MAX; j += i)
                if (A[j] == -1)
                    A[j] = i;
        }
    }
}