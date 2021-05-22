class Solution
{
public:
    char slowestKey(vector<int> &rt, string s)
    {
        int n = rt.size();
        int _mx = rt[0], ans = s[0];

        for (int i = 1; i < n; ++i)
        {
            int d = rt[i] - rt[i - 1];
            if (d > _mx)
            {
                _mx = d;
                ans = s[i];
            }
            else if (d == _mx)
            {
                ans = max(ans, (int)s[i]);
            }
        }

        return ans;
    }
};