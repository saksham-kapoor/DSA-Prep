class Solution
{
    pair<int, int> calculate01(string s)
    {
        int zeros, ones;
        zeros = ones = 0;
        for (char i : s)
        {
            if (i == '0')
                zeros++;
            else
                ones++;
        }
        return {zeros, ones};
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int length = strs.size();
        vector<pair<int, int>> fz;
        for (auto i : strs)
            fz.push_back(calculate01(i));

        int t[length + 1][m + 1][n + 1];

        // init
        for (int i = 0; i <= length; i++)
            t[i][0][0] = 0;
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                t[0][j][k] = 0;
            }
        }

        // dp
        for (int i = 1; i <= length; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {

                    int n0 = fz[i - 1].first, n1 = fz[i - 1].second;

                    if (n0 <= j && n1 <= k)
                    {
                        t[i][j][k] = max(1 + t[i - 1][j - n0][k - n1], t[i - 1][j][k]);
                    }
                    else
                    {
                        t[i][j][k] = t[i - 1][j][k];
                    }
                }
            }
        }

        return t[length][m][n];
    }
};