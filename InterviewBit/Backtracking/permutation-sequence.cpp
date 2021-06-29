class Solution
{
public:
    string getPermutation(int n, int k)
    {
        --k;

        int f[10];
        vector<int> num(9, 0);
        f[0] = f[1] = 1;
        num[0] = 1;

        for (int i = 2; i <= 9; ++i)
            f[i] = i * f[i - 1], num[i - 1] = i;

        // construct string
        // idx * f[n - i] <= k for it to be valid!
        string res;
        for (int i = 1; i <= n; ++i)
        {
            int fac = f[n - i];
            int idx = k / fac;

            k -= idx * fac;
            res.push_back('0' + num[idx]);
            num.erase(num.begin() + idx);
        }

        return res;
    }
};