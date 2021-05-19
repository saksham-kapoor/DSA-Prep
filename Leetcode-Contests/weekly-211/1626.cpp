class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {

        // set up begin #################
        int n = ages.size();
        pair<int, int> p[n];

        for (int i = 0; i < n; ++i)
            p[i] = {ages[i], scores[i]};

        sort(p, p + n);
        // set up end ###############

        int t[n];
        int res = p[0].second;

        for (int i = 0; i < n; ++i)
        {
            int mx = 0;

            for (int j = 0; j < i; ++j)
            {
                if (p[j].second <= p[i].second)
                {
                    mx = max(mx, t[j]);
                }
            }

            t[i] = mx + p[i].second;
            res = max(res, t[i]);
        }

        return res;
    }
};