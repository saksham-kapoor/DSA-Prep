class Solution
{
    int t[501][501];
    int helper(vector<int> &sv, int prefix[], int i, int j)
    {
        if (i == j)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        int ans = 0;
        for (int k = i; k < j; ++k)
        {
            int sum_left = prefix[k + 1] - prefix[i], sum_right = prefix[j + 1] - prefix[k + 1];

            if (sum_left < sum_right)
            {
                ans = max(ans, sum_left + helper(sv, prefix, i, k));
            }
            else if (sum_left > sum_right)
            {
                ans = max(ans, sum_right + helper(sv, prefix, k + 1, j));
            }
            else
            {
                ans = max(ans, max(sum_right + helper(sv, prefix, i, k), sum_left + helper(sv, prefix, k + 1, j)));
            }
        }

        return t[i][j] = ans;
    }

public:
    int stoneGameV(vector<int> &sv)
    {
        int n = sv.size();
        int prefix[n + 1];
        memset(t, -1, sizeof(t));
        memset(prefix, 0, sizeof(prefix));

        for (int i = 0; i < (int)sv.size(); ++i)
        {
            prefix[i + 1] = prefix[i] + sv[i];
        }

        return helper(sv, prefix, 0, (int)sv.size() - 1);
    }
};