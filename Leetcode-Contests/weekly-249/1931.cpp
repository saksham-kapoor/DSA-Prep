// Beautiful!!!!!

class Solution
{
    string colors = "RGB";
    int mod = 1e9 + 7;

    void generate(vector<string> &all_combinations, string &&op, char prev, int m)
    {
        if (m == 0)
        {
            all_combinations.push_back(op);
            return;
        }

        for (char &c : colors)
            if (c != prev)
                generate(all_combinations, op + c, c, m - 1);
    }

    int dp[250][1001];
    int solve(int state, int col, vector<int> adj[])
    {
        if (col == 0)
            return 1;
        if (dp[state][col] != -1)
            return dp[state][col];

        long long ans = 0;
        for (int &v : adj[state])
            ans = (ans + solve(v, col - 1, adj)) % mod;
        return dp[state][col] = ans;
    }

public:
    int colorTheGrid(int m, int n)
    {
        // generate all possible combinations
        vector<string> all_combinations;
        generate(all_combinations, "", '*', m);

        int states = all_combinations.size();
        vector<int> adj[states];
        bool flag;

        // create adj
        for (int i = 0; i < states; ++i)
            for (int j = i + 1; j < states; ++j)
            {
                flag = false;
                for (int k = 0; k < m; ++k)
                    if (all_combinations[i][k] == all_combinations[j][k])
                    {
                        flag = true;
                        break;
                    }
                if (!flag)
                    adj[i].push_back(j), adj[j].push_back(i);
            }

        memset(dp, -1, sizeof(dp));
        int ans = 0;

        for (int i = 0; i < states; ++i)
            ans = (ans + solve(i, n - 1, adj)) % mod;

        return ans;
    }
};