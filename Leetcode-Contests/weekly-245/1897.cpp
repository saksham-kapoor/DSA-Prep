// SIMPLE SOLUTION
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int fz[26] = {};
        for (auto &w : words)
        {
            for (auto &c : w)
                fz[c - 'a']++;
        }

        for (auto &f : fz)
            if (f % words.size() != 0)
                return false;
        return true;
    }
};

// STL SOLUTION
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int fz[26] = {};
        for (auto &w : words)
        {
            for (auto &c : w)
                fz[c - 'a']++;
        }

        // if every element satisfies condition returns true, else return false
        return all_of(fz, fz + 26, [&](auto &f)
                      { return f % words.size() == 0; });
    }
};