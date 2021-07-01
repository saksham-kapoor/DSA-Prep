// Very elegant
// max number - 99999 -> box number = 9*5 = 45, so max 45 boxes will be there!
// good observations always help!
class Solution
{
    int calc(int i)
    {
        int res = 0;
        while (i)
            res += i % 10, i /= 10;
        return res;
    }

public:
    int countBalls(int lo, int hi)
    {
        int mp[46] = {};

        for (int i = lo; i <= hi; ++i)
            mp[calc(i)]++;

        return *max_element(mp, mp + 46);
    }
};

// unordered_map method
// complexity wise, equally faster than other method
// might not be the most elegant

class Solution
{
    int calc(int i)
    {
        int res = 0;
        while (i)
            res += i % 10, i /= 10;
        return res;
    }

public:
    int countBalls(int lo, int hi)
    {
        unordered_map<int, int> mp;

        int res = 0;
        for (int i = lo; i <= hi; ++i)
            mp[calc(i)]++;

        for (auto &[n, cnt] : mp)
            res = max(res, cnt);

        return res;
    }
};