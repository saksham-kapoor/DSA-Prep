class Solution
{
    static const int MOD = 1e9 + 7;

public:
    int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes)
    {
        sort(packages.begin(), packages.end());

        for (int i = 0; i < boxes.size(); ++i)
            sort(boxes[i].begin(), boxes[i].end());

        unsigned long res = ULLONG_MAX, sum = 0;

        for (int i = 0; i < packages.size(); ++i)
            sum += packages[i];

        for (int i = 0; i < boxes.size(); ++i)
        {
            if (boxes[i].back() < packages.back())
                continue;

            int idx = 0;
            unsigned long curr = 0;

            for (int j = 0; j < boxes[i].size(); ++j)
            {
                if (j != 0 && boxes[i][j] == boxes[i][j - 1])
                    continue;

                auto it = upper_bound(packages.begin() + idx, packages.end(), boxes[i][j]);
                curr += (it - packages.begin() - idx) * boxes[i][j];
                idx = it - packages.begin();
            }

            res = min(res, curr);
        }

        return res == ULONG_MAX ? -1 : (res - sum) % MOD;
    }
};