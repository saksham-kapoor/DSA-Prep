// MINIMUM 1 BIT OPERATIONS
// GRAAAY CODE!!
// N IS GIVEN IN GRAY CODE
// CONVERT THAT TO BINARY!
// FORMULAAA
// xor - right shift - xor ans so on till n becomes 0
class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int ans = 0;

        while (n != 0)
        {
            ans ^= n;
            n >>= 1;
        }

        return ans;
    }
};

// trace 1000
// then caculate this for n = 1110
class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        if (n <= 1)
            return n;

        int max_bit = 0;
        while ((1 << max_bit) <= n)
        {
            max_bit++;
        }
        max_bit -= 1;

        return ((1 << (max_bit + 1)) - 1) - minimumOneBitOperations(n ^ (1 << max_bit));
    }
};