class Solution
{
public:
    int minimumEffort(vector<vector<int>> &t)
    {
        sort(t.begin(), t.end(), [](auto &a, auto &b)
             { return a[1] - a[0] > b[1] - b[0]; });

        int e = 0, n = t.size(), mx = 0;
        for (int i = 0; i < n; ++i)
        {
            if (e < t[i][1])
            {
                mx += t[i][1] - e;
                e = t[i][1];
            }
            e -= t[i][0];
        }

        return mx;
    }
};