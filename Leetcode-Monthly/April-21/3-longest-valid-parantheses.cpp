class Solution
{
public:
    int longestValidParentheses(string str)
    {
        if (str.size() <= 1)
            return 0;
        stack<int> s;
        int maxLength = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                s.push(i);
            }
            else
            {
                if (s.empty())
                    s.push(i);
                else if (str[s.top()] == '(')
                {
                    s.pop();
                    if (s.empty())
                        maxLength = max(maxLength, i + 1);
                    else
                        maxLength = max(maxLength, i - s.top());
                }
                else
                    s.push(i);
            }
        }
        return maxLength;
    }
};