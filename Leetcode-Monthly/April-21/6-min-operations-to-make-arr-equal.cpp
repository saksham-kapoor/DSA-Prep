class Solution
{
public:
    int minOperations(int n)
    {
        return (n & 1) ? (n / 2) * (n / 2 + 1) : (n / 2) * (n / 2);
    }
};