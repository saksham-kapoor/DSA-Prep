// Try not to get too intimidated by graph questions
// Just remember the standard algorithms
// and try to fit them wherever possible
// learn how to modify and use these standard algorithms

class Solution
{

    int dijkstra(vector<array<int, 2>> adj[], int cost[], vector<int> &fees, int time[], int maxTime)
    {
        cost[0] = 0;
        time[0] = 0;

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty())
        {
            array<int, 3> info = pq.top();
            pq.pop();

            int c = info[0], t = info[1], curr_node = info[2];

            if (curr_node == fees.size() - 1)
                return c;

            for (auto &nodes : adj[curr_node])
            {
                int node = nodes[0], travel_time = nodes[1];

                if (t + travel_time <= maxTime)
                {
                    if (c + fees[curr_node] < cost[node] || t + travel_time < time[node])
                    {
                        cost[node] = c + fees[curr_node];
                        time[node] = t + travel_time;
                        pq.push({cost[node], time[node], node});
                    }
                }
            }
        }

        return INT_MAX;
    }

public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &fees)
    {
        int n = fees.size();
        // create adj matrix
        vector<array<int, 2>> adj[n];
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]}); // node, time
            adj[e[1]].push_back({e[0], e[2]}); // node, time
        }

        int cost[1001], time[1001];
        for (int i = 0; i < 1001; ++i)
            cost[i] = time[i] = INT_MAX;

        int res = dijkstra(adj, cost, fees, time, maxTime);
        return res == INT_MAX ? -1 : res + fees[n - 1];
    }
};