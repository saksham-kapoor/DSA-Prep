// Simple Solution
class Solution
{
public:
    string largestOddNumber(string s)
    {
        int idx = s.size() - 1;

        while (idx >= 0 && (s[idx] - '0') % 2 == 0)
            --idx;

        return s.substr(0, idx + 1);
    }
};

// 1 liner
class Solution
{
public:
    string largestOddNumber(string s)
    {
        return s.substr(0, s.find_last_of("13579") + 1);
    }
};