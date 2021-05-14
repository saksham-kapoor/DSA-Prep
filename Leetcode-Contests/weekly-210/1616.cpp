class Solution
{
    int n;
    bool solve(string &a, string &b)
    {
        int i = 0, j = n - 1;

        while (i < j && a[i] == b[j])
            ++i, --j;

        return isP(a, i, j) || isP(b, i, j);
    }
    bool isP(string &s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }

public:
    bool checkPalindromeFormation(string a, string b)
    {
        n = a.size();

        bool ans = solve(a, b) || solve(b, a);

        return ans;
    }
};