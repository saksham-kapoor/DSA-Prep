class Solution
{
public:
    vector<vector<int>> graph;
    vector<int> ranks;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        graph.resize(n);
        for (auto &conn : connections)
        {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        ranks.resize(n, -2);

        vector<vector<int>> res;
        dfs(0, 0, res);
        return res;
    }

    int dfs(int node, int rank, vector<vector<int>> &res)
    {
        if (ranks[node] >= 0)
            return ranks[node];

        ranks[node] = rank;
        int minRank = rank;

        for (auto neighbor : graph[node])
        {
            if (ranks[neighbor] == rank - 1 || ranks[neighbor] > rank)
                continue;

            int neighborRank = dfs(neighbor, rank + 1, res);
            minRank = min(minRank, neighborRank);
            if (neighborRank > rank)
                res.push_back({node, neighbor});
        }
        return minRank;
    }
};