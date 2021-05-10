// BEAUTIFUL BITS SOLUTION
// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/discuss/855690/C%2B%2B-iterative-100ms-beats-100-with-bit-twiddling

/*

We call these vertical lines, fences.
This is how we divide the string into substrings

Since we have to check all possible solutions, we can use bits!

As there will be max n-1 fences, we can have max 2^(n-1) variations
[as each fence can have 2 options, either it exists or not]

a1 | a2 | a3    => 1 1
a1 | a2 a3      => 1 0
a1 a2 | a3      => 0 1
a1 a2 a3        => 0 0

1 means fence exists, 0 means it doesn't

Number of set bits in 'fences' = number of string partitions

*/

class Solution
{
public:
    int maxUniqueSplit(string s)
    {
        int ans = 1, n = s.size();

        for (int fences = (1 << (n - 1)) - 1; fences >= 1; --fences)
        {

            if (__builtin_popcount(fences) < ans) // if fences < current max number of substrings [redundant]
                continue;

            unordered_set<string> st;
            string new_str = {s[0]};

            for (int i = 0; i < n - 1; ++i)
            {

                if (fences & (1 << i))
                {
                    st.insert(new_str);
                    new_str = {s[i + 1]};
                }
                else
                {
                    new_str.push_back(s[i + 1]);
                }
            }

            if (new_str.size())
                st.insert(new_str);

            ans = max(ans, (int)st.size()); // st.size(), denotes number of unique substrings
        }

        return ans;
    }
};

// BACKTRACKING SOLUTION
class Solution
{
    int solve(string &s, int start, unordered_set<string> &seen)
    {
        if (start == s.size())
            return 0;

        int ans = 0;
        string new_str;
        for (int i = start; i < s.size(); ++i)
        {
            new_str.push_back(s[i]);
            if (seen.find(new_str) == seen.end())
            {
                // choose
                seen.insert(new_str);

                // explore
                ans = max(ans, 1 + solve(s, i + 1, seen));

                // unchoose
                seen.erase(new_str);
            }
        }

        return ans;
    }

public:
    int maxUniqueSplit(string s)
    {
        unordered_set<string> seen;
        return solve(s, 0, seen);
    }
};