/*
    Simple Brute Force DFS Solution!
*/

class Solution
{
    string ans;
    unordered_set<string> vis;
    int a, b, n;

    string add(string s)
    {
        for (int i = 1; i < s.size(); i += 2)
        {
            int v = (s[i] - '0' + a) % 10;
            s[i] = v + '0';
        }
        return s;
    }

    string rotate(string s)
    {
        return s.substr(n - b, b) + s.substr(0, n - b);
    }

    void dfs(string s)
    {
        if (vis.find(s) != vis.end())
            return;

        ans = min(ans, s);
        vis.insert(s);

        dfs(add(s));
        dfs(rotate(s));
    }

public:
    string findLexSmallestString(string s, int a, int b)
    {
        ans = s;
        this->a = a;
        this->b = b;
        n = s.size();

        dfs(s);

        return ans;
    }
};