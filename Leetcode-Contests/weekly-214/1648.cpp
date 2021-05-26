// Simple Greedy Solution
class Solution
{
    const static int MOD = 1e9 + 7;

    int sum(long long n, long long k, int num)
    {
        long long sum1 = n * (n + 1) / 2;
        long long sum2 = k * (k + 1) / 2;
        return ((sum1 - sum2) * num) % MOD;
    }

public:
    int maxProfit(vector<int> &inv, int orders)
    {
        long long ans = 0;
        int i = 0, n = inv.size();

        sort(inv.begin(), inv.end(), greater<int>());
        inv.push_back(0);

        while (i < n)
        {
            while (inv[i] == inv[i + 1])
                ++i;

            int h = inv[i] - inv[i + 1];

            if (orders - (i + 1) * h < 0)
                break;

            ans += sum(inv[i], inv[i] - h, i + 1);
            orders -= (i + 1) * h;
            ++i;
        }

        if (orders)
        {
            int h = orders / (i + 1);
            int r = orders % (i + 1);
            if (h)
                ans += sum(inv[i], inv[i] - h, i + 1);

            if (r)
                ans += (long long)r * (inv[i] - h);
        }

        return ans % MOD;
    }
};

// Binary Search With Map
class Solution
{
    const static int MOD = 1e9 + 7;

    int sum(long long n, long long k, int num)
    {
        long long sum1 = n * (n + 1) / 2;
        long long sum2 = k * (k + 1) / 2;
        return ((sum1 - sum2) * num) % MOD;
    }

    bool is_valid(map<int, int, greater<int>> &mp, int &k, int &orders)
    {
        long num = 0;
        for (auto &[h, cnt] : mp)
        {
            if (h < k)
                break;
            num += (long)(h - k + 1) * cnt;
        }
        return num >= orders;
    }

public:
    int maxProfit(vector<int> &inv, int orders)
    {
        map<int, int, greater<int>> mp;

        for (int i = 0; i < inv.size(); ++i)
            mp[inv[i]]++;

        int start = 1, end = mp.begin()->first, res = 0;
        // res stores highest valid height

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (is_valid(mp, mid, orders))
            {
                res = mid;
                start = mid + 1; // if mid is valid, we will check higher heights
            }
            else
                end = mid - 1; // check lower heights
        }

        long ans = 0;
        for (auto &[val, cnt] : mp)
        {
            if (val <= res)
                break;

            ans = (ans + sum(val, res, cnt)) % MOD;
            orders -= (val - res) * cnt;
        }

        ans = (ans + (long)orders * res) % MOD;
        return ans;
    }
};

// Binary Search Solution using simple array
class Solution
{
    const static int MOD = 1e9 + 7;

    int sum(long long n, long long k, int num)
    {
        long long sum1 = n * (n + 1) / 2;
        long long sum2 = k * (k + 1) / 2;
        return ((sum1 - sum2) * num) % MOD;
    }

    bool isValid(vector<int> &inv, int &k, int &orders)
    {
        long cnt = 0;
        for (int i = 0; i < inv.size() && inv[i] >= k; ++i)
        {
            cnt += inv[i] - k + 1;
        }

        return cnt >= (long)orders;
    }

public:
    int maxProfit(vector<int> &inv, int orders)
    {
        sort(inv.begin(), inv.end(), greater<int>());
        int i = 0, j = inv[0], res = 0, mid = 0;

        while (i <= j)
        {
            mid = i + (j - i) / 2;

            if (isValid(inv, mid, orders))
            {
                res = mid;
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        // res stores the last valid height at which all balls above + including it >= orders
        /*

        5   0
        4   0
        3   0 0 
        2   0 0
        1   0 0
        -------
        if orders = 3,

        for res = 2, balls = 6
        for res = 3, balls = 4
        for res = 4, balls = 2

        therefore res = 3 is the last valid height
        so we remove all balls above height 3 first, i.e at heights 4 and 5
        now remaining balls we can remove from height 3

        */

        long ans = 0;

        for (int i = 0; i < inv.size() && inv[i] > res; ++i)
        {
            long amt = sum(inv[i], res, 1);
            ans = (ans + amt) % MOD;
            orders -= (inv[i] - res);
        }

        ans = (ans + (long)orders * res) % MOD;
        return ans % MOD;
    }
};