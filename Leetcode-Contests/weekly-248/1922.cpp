#define ll long long
#define mod (ll)(1e9 + 7)

class Solution
{
    int calc(ll x, ll n)
    {
        if (n == 0)
            return 1;

        if (n % 2 == 0)
            return calc((x * x) % mod, n / 2);

        return (x * calc((x * x) % mod, n / 2)) % mod;
    }

public:
    int countGoodNumbers(ll n)
    {
        ll res = 1, odd = n / 2, even = n - n / 2;

        res = (res * calc(5, even) % mod) % mod;
        res = (res * calc(4, odd) % mod) % mod;

        return res;
    }
};