class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size(); // number of nodes
        vector<int> adj[n];
        vector<int> indeg(n, 0);

        // create adj list
        for (auto &e : edges)
        {
            if (e[0] == e[1])
                return -1;

            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        // push all nodes with indeg == 0 in queue
        vector<array<int, 26>> cs(n, array<int, 26>{});
        queue<int> nodes;
        for (int i = 0; i < n; ++i)
        {
            if (indeg[i] == 0)
            {
                nodes.push(i);
                cs[i][colors[i] - 'a'] = 1;
            }
        }

        // each node will save color frequency
        int count = 0;

        int ans = 0;
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();

            int val = *max_element(cs[node].begin(), cs[node].end());
            ans = max(ans, val);

            for (auto &i : adj[node])
            {
                int col = colors[i] - 'a'; // color of node
                for (int k = 0; k < 26; ++k)
                {
                    cs[i][k] = max(cs[i][k], cs[node][k] + (k == col));
                }
                indeg[i]--;
                if (indeg[i] == 0)
                    nodes.push(i);
            }

            count++; // increment count after processing each node
        }

        if (count != n) // graph has cycle
            return -1;

        return ans;
    }
};