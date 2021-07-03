class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int mask = 0, res = 0;
        unordered_map<char, int> vowels = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        array<int, 33> pos;
        pos.fill(-2);

        pos[0] = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (vowels.find(s[i]) != vowels.end())
                mask ^= (1 << vowels[s[i]]);

            if (pos[mask] == -2)
                pos[mask] = i;
            else
                res = max(res, i - pos[mask]);
        }

        return res;
    }
};