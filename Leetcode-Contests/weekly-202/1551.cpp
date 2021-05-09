class Solution
{
public:
    int minOperations(int n)
    {
        if (n & 1)
            return (n / 2) * (n / 2) + (n / 2);

        // n is even
        return (n / 2) * (n / 2);
    }
};