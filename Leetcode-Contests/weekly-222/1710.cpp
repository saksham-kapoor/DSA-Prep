class Solution
{
public:
    int maximumUnits(vector<vector<int>> &b, int k)
    {
        int res = 0;

        sort(b.begin(), b.end(), [](auto &a, auto &b)
             { return a[1] > b[1]; });

        for (int i = 0; i < b.size(); ++i)
            if (b[i][0] <= k)
            {
                res += b[i][0] * b[i][1];
                k -= b[i][0];
            }
            else
            {
                res += k * b[i][1];
                break;
            }

        return res;
    }
};