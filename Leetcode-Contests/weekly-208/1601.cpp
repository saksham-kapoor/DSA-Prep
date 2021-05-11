/*
    OPTIMISATION PROBLEM -> MAXIMISE SOMETHING!
    GREEDY OR DP!
    CONSTRAINTS ARE EXTREMELY SMALL -> SUGGESTS, DP OR BACKTRACKING!
    
    CONCEPT -
    Take all combination of requests, and check if they satisfy the condition
    return maxlength

*/

class Solution
{
    int ans;

    void solve(vector<vector<int>> &r, int idx, vector<int> &v, int cnt)
    {
        if (idx == r.size())
        {
            for (auto &i : v)
            {
                if (i != 0)
                    return;
            }

            ans = max(ans, cnt);
            return;
        }

        // OPTION 1 -> take this
        v[r[idx][0]]--;                // CHOOSE
        v[r[idx][1]]++;                // CHOOSE
        solve(r, idx + 1, v, cnt + 1); // EXPLORE
        v[r[idx][0]]++;                // UNCHOOSE
        v[r[idx][1]]--;                // UNCHOOSE

        // OPTION 2 -> do not take this
        solve(r, idx + 1, v, cnt);
    }

public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        ans = 0;
        vector<int> v(n, 0);

        solve(requests, 0, v, 0);
        return ans;
    }
};

// BIT METHOD
class Solution
{
public:
    int maximumRequests(int n, vector<vector<int>> &req)
    {
        int taken = 0, ans = 0;
        vector<int> p;

        for (int i = 0; i < req.size(); ++i)
        {
            if (req[i][0] == req[i][1])
                taken++;
            else
            {
                p.push_back(i);
            }
        }

        int m = p.size();
        if (m == 0 || m == 1) // optional
            return taken;

        for (int comb = (1 << m) - 1; comb >= 1; --comb)
        {

            if (ans > __builtin_popcount(comb))
                continue;

            vector<int> v(n, 0);

            for (int i = 0; i < m; ++i)
            {
                if (comb & (1 << i))
                {
                    int from = req[p[i]][0], to = req[p[i]][1];

                    --v[from];
                    ++v[to];
                }
            }

            int i;
            for (i = 0; i < n; ++i)
            {
                if (v[i] != 0)
                    break;
            }

            if (i == n)
                ans = max(ans, __builtin_popcount(comb));
        }

        return ans + taken;
    }
};