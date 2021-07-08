// Simple djikstra
// use max distances instead of min distances

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        // create adj list
        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        double dist[10001] = {};
        dist[start] = 1;

        priority_queue<pair<double, int>> pq; // prob, node
        pq.emplace(dist[start], start);

        while (pq.size())
        {
            auto [curr, node] = pq.top();
            pq.pop();

            if (node == end)
                return curr;

            for (auto &[i, p] : adj[node])
            {
                if (curr * p > dist[i])
                {
                    dist[i] = curr * p;
                    pq.emplace(dist[i], i);
                }
            }
        }

        return 0; // no path
    }
};