// Without Stack
class Solution
{
public:
    int maxDepth(string s)
    {
        int cnt = 0, ans = 0;

        for (auto &i : s)
        {
            if (i == '(')
                ans = max(ans, ++cnt);
            else if (i == ')')
                --cnt;
        }

        return ans;
    }
};

// With Stack
class Solution
{
public:
    int maxDepth(string s)
    {
        stack<char> st;
        int cnt = 0;
        for (auto &i : s)
        {
            if (i == '(')
                st.push(i);
            else if (i == ')')
                st.pop();
            cnt = max(cnt, (int)st.size());
        }

        return cnt;
    }
};