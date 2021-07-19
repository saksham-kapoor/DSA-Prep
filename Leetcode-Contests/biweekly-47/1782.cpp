// How to count pairs where sum > k in O(N) =>> 2 sum (2 pointer method)

class Solution
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        int edge_count[n + 1], sorted_edge_count[n + 1];
        memset(edge_count, 0, sizeof(edge_count));
        memset(sorted_edge_count, 0, sizeof(sorted_edge_count));

        unordered_map<int, int> shared[n + 1];

        for (auto &e : edges)
        {
            sorted_edge_count[e[0]] = ++edge_count[e[0]];
            sorted_edge_count[e[1]] = ++edge_count[e[1]];
            ++shared[min(e[0], e[1])][max(e[0], e[1])];
        }

        sort(sorted_edge_count, sorted_edge_count + n + 1);

        vector<int> res((int)queries.size());
        int k = 0;

        for (auto &q : queries)
        {
            int ans = 0, i = 1, j = n;

            while (i < j)
            {
                int sum = sorted_edge_count[i] + sorted_edge_count[j];
                if (sum > q)
                {
                    ans += j - i, --j;
                }
                else
                    ++i;
            }

            // subtract pairs where shared[i][j] makes the sum smaller
            for (int i = 1; i <= n; ++i)
            {
                for (auto [j, cnt] : shared[i])
                {
                    if (edge_count[i] + edge_count[j] > q && edge_count[i] + edge_count[j] <= q + cnt)
                        --ans;
                }
            }

            res[k++] = ans;
        }

        return res;
    }
};