// As pleasant as it seems, it does not make sense to eat oranges one by one.

// So, the choice we have is to eat n % 2 oranges one-by-one and then swallow n / 2, or eat n % 3 oranges so that we can gobble 2 * n / 3
unordered_map<int, int> t;
class Solution
{
public:
    int minDays(int n)
    {
        if (n <= 1)
            return n;

        if (t.find(n) != t.end())
            return t[n];

        return t[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
    }
};