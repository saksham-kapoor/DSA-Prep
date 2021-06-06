// Cleaner code and faster as we don't use set now
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int ac = 0, cnt = words.size();

        for (int i = 0; i < (int)allowed.size(); ++i)
            ac |= (1 << (allowed[i] - 'a'));

        for (auto &w : words)
            for (auto &c : w)
                if ((ac & (1 << (c - 'a'))) == 0)
                {
                    --cnt;
                    break;
                }

        return cnt;
    }
};

// O(N*W)
// N -> number of string, W -> max length of string
// Time consuming step -> searching in set, can be improved by using bitmask
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        unordered_set<int> st(allowed.begin(), allowed.end());
        int cnt = 0;

        for (auto &s : words)
        {
            int i = 0;

            for (; i < s.size(); ++i)
                if (st.find(s[i]) == st.end())
                    break;

            cnt += i == s.size() ? 1 : 0;
        }

        return cnt;
    }
};