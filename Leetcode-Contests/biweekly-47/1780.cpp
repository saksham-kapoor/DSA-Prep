// 3^x(1 + 3^y + 3^z ...)
// divide by 3^x
// 1 + 3^y + 3^z ...
// if num % 3 == 1, simply subtract 1
// and repeat ----> recursive solution!

// remainder can never be 2

// WHOLE IDEA -> Keep on substracting powers of 3 from number till number == 0

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        if (n == 0)
            return true;

        if (n % 3 == 2)
            return false;

        return checkPowersOfThree(n / 3);
    }
};