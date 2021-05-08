class Solution
{
    unordered_set<int> unhappy;
    void check(int &x, int &y, int &u, int &v, vector<vector<int>> &pos)
    {
        // x prefers u over y
        // u prefers x over v
        if (pos[u][x] < pos[y][x] && pos[x][u] < pos[v][u])
        {
            unhappy.insert(x);
            unhappy.insert(u);
        }
    }

public:
    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
    {
        vector<vector<int>> pos(n, vector<int>(n, 0));

        // pos[i][j] means position of i in j
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                pos[preferences[i][j]][i] = j;
            }
        }

        // TRAVERSE ALL PAIRS
        for (int i = 0; i < pairs.size() - 1; ++i)
        {
            for (int j = i + 1; j < pairs.size(); ++j)
            {
                int x = pairs[i][0], y = pairs[i][1], u = pairs[j][0], v = pairs[j][1];
                check(x, y, u, v, pos);
                check(x, y, v, u, pos);
                check(y, x, u, v, pos);
                check(y, x, v, u, pos);
            }
        }

        return unhappy.size();
    }
};