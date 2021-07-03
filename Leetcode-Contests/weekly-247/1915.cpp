class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long long res = 0;
        int cnt[1025] = {};
        cnt[0] = 1;

        int mask = 0;
        for (auto &c : word)
        {
            mask ^= (1 << (c - 'a'));

            // add strings with all even ending at this point
            res += cnt[mask];

            // flip each character one by one, this character occurs odd number of times and rest occur even number of times!
            // count occurences of such masks
            for (int j = 'a'; j <= 'j'; ++j)
                res += cnt[mask ^ (1 << (j - 'a'))];

            cnt[mask]++;
        }

        return res;
    }
};