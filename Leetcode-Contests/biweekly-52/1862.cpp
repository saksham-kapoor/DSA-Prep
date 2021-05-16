class Solution
{
    // nice way to store constants
    const static int MAX = 1e5;
    const static long long MOD = 1e9 + 7;

public:
    int sumOfFlooredPairs(vector<int> &A)
    {
        unsigned long long ans = 0;
        int fz[MAX + 1] = {};

        // simply store fz of numbers
        for (int i = 0; i < (int)A.size(); ++i)
            fz[A[i]]++;

        // calculate prefix sum of fz
        // now fz[i] will denote number of elements <= i in array
        for (int i = 1; i <= MAX; ++i)
            fz[i] += fz[i - 1];

        // if we need number of elemets >= i but less than k
        // fz[k - 1] - fz[i - 1]

        for (int i = 1; i <= MAX; ++i)
            if (fz[i] > fz[i - 1]) // will only be true for numbers present in given array
            {
                unsigned long long sum = 0;
                for (int j = 1; j * i <= MAX; ++j)
                {
                    int lower = i * j - 1;
                    int upper = i * (j + 1) - 1;

                    // number of values [a, b)
                    // here j denotes the quotient
                    unsigned long long num_vals = fz[min(upper, MAX)] - fz[lower];
                    sum += (num_vals * j) % MOD; // means number of values that give quotient j * j when divisor  = A[i]
                }

                // if duplicates
                // fz[i] - fz[i - 1] will give fz of i in given array
                ans += (sum * (fz[i] - fz[i - 1])) % MOD;
            }

        return ans % MOD;
    }
};