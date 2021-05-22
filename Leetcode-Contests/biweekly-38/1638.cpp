// Better Method
// https://leetcode.com/problems/count-substrings-that-differ-by-one-character/discuss/917690/C%2B%2B-O(N3)-with-explanation
class Solution
{
public:
    int countSubstrings(string s, string t)
    {
        int n = s.size(), m = t.size(), cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (s[i] == t[j])
                    continue;

                int left = 1, right = 1;
                while (i - left >= 0 && j - left >= 0 && s[i - left] == t[j - left])
                    ++left;
                while (i + right < n && j + right < m && s[i + right] == t[j + right])
                    ++right;
                cnt += left * right;
            }
        }

        return cnt;
    }
};

// Brute Force (Extremely Slow) -> O(n^4)
class Solution
{
public:
    int countSubstrings(string s, string t)
    {
        int n = t.size();
        unordered_map<string, int> fz;
        unordered_set<char> chars;
        string sub;

        for (int i = 0; i < n; ++i)
        {
            sub.clear();
            chars.insert(t[i]);
            for (int j = i; j < n; ++j)
            {
                sub.push_back(t[j]);
                fz[sub]++;
            }
        }

        int cnt = 0;

        for (int i = 0; i < (int)s.size(); ++i)
        {
            sub.clear();
            for (int j = i; j < (int)s.size(); ++j)
            {
                sub.push_back(s[j]);

                // main
                for (int k = 0; k < sub.size(); ++k)
                {
                    for (auto &c : chars)
                    {
                        char og = sub[k];

                        if (c == og)
                            continue;

                        sub[k] = c;
                        // cout << sub << "   ";
                        auto it = fz.find(sub);
                        if (it != fz.end())
                            cnt += it->second;

                        sub[k] = og;
                    }
                }
            }
        }

        return cnt;
    }
};