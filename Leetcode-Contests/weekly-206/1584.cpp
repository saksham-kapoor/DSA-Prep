class UnionFind
{
    vector<int> c;

public:
    UnionFind(int n)
    {
        c.resize(n);
        iota(c.begin(), c.end(), 0);
    }

    // parent
    int parent(int a)
    {
        if (c[a] == a)
            return a;
        return c[a] = parent(c[a]);
    }

    // unite
    bool unite(int a, int b)
    {
        if (parent(a) == parent(b))
            return false;

        c[parent(a)] = b;
        return true;
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<array<int, 3>> edges;

        for (int i = 0; i < points.size() - 1; ++i)
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                int x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];
                int cost = abs(x1 - x2) + abs(y1 - y2);

                edges.push_back({cost, i, j});
            }
        }

        // O(n) time! (n = number of edges)
        // converts array to heap
        make_heap(edges.begin(), edges.end(), greater<array<int, 3>>());

        int min_cost = 0, num_edges = 0;
        UnionFind graph(points.size());

        // O(klog(n*n)) is much smaller than O(n*nlog(n*n))
        // n*n as n*n = number of edges
        // k => number of required edges
        while (!edges.empty())
        {
            // pop_heap => gives us the top element in arr.back() position and detaches it from the heap
            pop_heap(edges.begin(), edges.end(), greater<array<int, 3>>()); // O(log(n*n))
            auto &[cost, i, j] = edges.back();
            edges.pop_back();

            if (graph.unite(i, j))
            {
                min_cost += cost;
                num_edges++;

                if (num_edges == points.size() - 1)
                    break;
            }
        }

        return min_cost;
    }
};