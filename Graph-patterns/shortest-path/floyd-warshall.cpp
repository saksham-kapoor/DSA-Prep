// ALL PAIR SHORTEST PATH
// O(V^3)
// SHORTEST DISTANCE OF A NODE WITH ITSELF IS ALWAYS 0
// IF SHORTEST DISTANCE OF A NODE WITH ITSELF < 0 =====> NEGATIVE EGDE WEIGHT CYCLE

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &d)
    {
        int n = d.size();
        for (int k = 0; k < n; ++k)         // via node
            for (int i = 0; i < n; ++i)     // source node
                for (int j = 0; j < n; ++j) // destination node
                    if (d[i][k] == -1 || d[k][j] == -1)
                        continue;
                    else if (d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];

        for (int i = 0; i < n; ++i)
            if (d[i][i] < 0)
            {
                cout << "negative edge weight cycle"
                     << "\n";
                break;
            }
    }
};
