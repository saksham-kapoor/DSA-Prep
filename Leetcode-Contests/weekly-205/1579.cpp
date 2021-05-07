/*
    CONCEPT
    
    We will maintain two graphs, one for bob and one for alice.
    Basically, we need to generate the graphs with minimum possible edges.
    We will give higher priority to the common edges.
    
    Generating graphs with minimum possible edges
    => UNION FIND Method
    => This method will detect as soon as we put a redundant edge, so we discard it
    => We will also keep track of distinct components in graph, in the end, distict components == 1 for the graph to be fully traversable
    => distict components == 1 means graph is connected with N-1 edges!

*/

class UnionFind
{
    vector<int> components;
    int distinct_components;

public:
    // init
    UnionFind(int n)
    {
        for (int i = 0; i <= n; ++i)
        {
            components.push_back(i);
        }
        distinct_components = n;
    }

    // find parent
    int parent(int a)
    {
        if (components[a] == a)
            return a;
        return components[a] = parent(components[a]); // path compression!
    }

    // combine
    bool unite(int a, int b)
    {
        if (parent(a) == parent(b))
            return false; // redundant edge, discard (as this edge forms cycle)

        components[parent(a)] = b;
        distinct_components -= 1;
        return true;
    }

    // check if graph is fully traversable or not
    bool is_traversable()
    {
        return distinct_components == 1;
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        // type 3 edges have more priority than other edges
        // therefore we need it first
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] > b[0];
        });

        // create 2 graphs, as in 2 unionfind objects
        UnionFind alice(n), bob(n);

        // maintain total count of valid edges used
        int edges_used = 0;

        for (auto &e : edges)
        {
            int type = e[0], edge_start = e[1], edge_end = e[2];

            switch (type)
            {
            case 3:
                edges_used += (bob.unite(edge_start, edge_end) | alice.unite(edge_start, edge_end));
                break;
            case 2:
                edges_used += bob.unite(edge_start, edge_end);
                break;
            case 1:
                edges_used += alice.unite(edge_start, edge_end);
                break;
            }
        }

        if (!bob.is_traversable() || !alice.is_traversable())
            return -1;

        return edges.size() - edges_used;
    }
};