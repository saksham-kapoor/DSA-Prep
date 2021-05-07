// READ THE QUESTION AGAIN!
// THERE ARE ONLY 3 POSSIBLE ANSWERS TO A '?'
// 'a', 'b' or 'c'

class Solution
{
public:
    string modifyString(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '?')
            {
                for (int c = (int)'a'; c <= (int)'c'; ++c)
                {
                    if ((i == 0 || s[i - 1] != c) && (i == s.size() - 1 || s[i + 1] != c))
                    {
                        s[i] = c;
                        break;
                    }
                }
            }
        }
        return s;
    }
};