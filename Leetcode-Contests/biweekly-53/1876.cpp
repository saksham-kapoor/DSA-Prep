// A More Generic Sliding Window Approach
class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int cnt = 0, n = s.size();
        unordered_map<char, int> mp;

        for (int i = 0; i < n; ++i)
        {
            if (i > 2 && --mp[s[i - 3]] == 0)
                mp.erase(s[i - 3]);
            mp[s[i]]++;
            if (mp.size() == 3)
                ++cnt;
        }

        return cnt;
    }
};

// Simple Approach For Window Size = 3
// Not Interview Worthy
// As we cannot extend this approach for multiple window sizes
class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int cnt = 0, n = s.size();

        for (int j = 0; j + 2 < n; ++j)
            cnt += s[j] != s[j + 1] && s[j + 1] != s[j + 2] && s[j] != s[j + 2];

        return cnt;
    }
};