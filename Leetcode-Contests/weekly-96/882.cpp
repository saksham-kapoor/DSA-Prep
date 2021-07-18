// less nodes
// always go for adj matrix

class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        int res = 0;

        // create adj matrix
        int graph[n][n];
        memset(graph, -1, sizeof(graph));
        for (auto &e : edges)
            graph[e[0]][e[1]] = graph[e[1]][e[0]] = e[2];

        // dijkstra
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [moves_made, node] = pq.top();
            pq.pop();

            if (vis[node] == 1)
                continue;
            vis[node] = 1;
            ++res;

            // try adj nodes
            for (int i = 0; i < n; ++i)
            {
                if (graph[node][i] != -1)
                {
                    if (graph[node][i] < maxMoves - moves_made)
                        pq.push({moves_made + graph[node][i] + 1, i});

                    res += min(maxMoves - moves_made, graph[node][i]);
                    graph[i][node] -= min(maxMoves - moves_made, graph[node][i]);
                }
            }
        }

        return res;
    }
};