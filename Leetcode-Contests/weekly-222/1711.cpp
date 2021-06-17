class Solution
{
    static const int MOD = 1e9 + 7;

public:
    int countPairs(vector<int> &d)
    {
        long long res = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < d.size(); ++i)
        {

            for (int k = 0; k <= 21; ++k)
            {
                if ((1 << k) < d[i])
                    continue;

                int target = (1 << k) - d[i];
                auto it = mp.find(target);

                if (it != mp.end())
                    res += it->second;
            }

            ++mp[d[i]];
        }

        return res % MOD;
    }
};