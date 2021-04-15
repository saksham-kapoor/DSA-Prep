// Iterative DP
// Bottom Up Approach
// O(1) space
// O(n) time
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;

        int arr[2], ans = 0;
        arr[0] = 0;
        arr[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            ans = arr[1] + arr[0];
            arr[0] = arr[1];
            arr[1] = ans;
        }
        return ans;
    }
};

// DP, Recursive + Memoization
// O(N) space and time
class Solution
{
    vector<int> t;

public:
    Solution() { t.resize(31, -1); }

    int fib(int n)
    {
        if (n == 0 || n == 1)
            return t[n] = n;
        if (t[n] != -1)
            return t[n];
        return t[n] = fib(n - 1) + fib(n - 2);
    }
};