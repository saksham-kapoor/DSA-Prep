/*

Method 1 -> Recursion
            Here, n can have huge numbers, so using a brute force simple recursion won't work
            and will result in function stack overflow
            
Method 2 -> While loop
            Here, n can have huge numbers, so a simple O(n) solution can result in TLE

Method 3 -> Idea -> Somehow reduce number of iterations.
            
            suppose n = 100
            ans = x^100
                = (x*x)^50
                [we reduced 50 iterations]
                = (x*x*x*x)^25
                [we reduced another 25 iterations]
                
            so instead of O(n) we do it in O(logn) time

*/

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;

        // int ranges from
        // -k .... 0 .... k-1
        // therefore, n*=-1 would result in 'int' out of bounds
        // so we decrease it first
        if (n == INT_MIN)
        {
            // INT_MIN is divisible by 2
            x = x * x;
            n = n / 2;
        }

        // will enter here in the first iteration only
        if (n < 0)
        {
            x = (1 / x);
            n *= -1;
        }

        // (n & 1)
        // returns true if n is odd
        return ((n & 1) ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2));
    }
};