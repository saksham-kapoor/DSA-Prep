class Solution
{
    int parent[10001] = {};
    int n;

    int find(int a)
    {
        if (parent[a] == a)
            return a;

        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b)
    {
        int pa = find(a), pb = find(b);
        if (pa != pb)
            parent[pb] = pa;
    }

    bool isConnected(int a, int b)
    {
        return find(a) == find(b);
    }

    void setup(int t)
    {
        // init parent array
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
        }

        //main setup
        for (int i = t + 1; i <= n; ++i)
        {
            int m = 2;
            while (i * m <= n)
            {
                unite(i, i * m);
                ++m;
            }
        }
    }

public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        this->n = n;
        vector<bool> ans((int)queries.size(), false);
        setup(threshold);

        int i = 0;
        for (auto &q : queries)
        {
            int a = q[0], b = q[1];
            if (isConnected(a, b))
                ans[i] = true;
            ++i;
        }

        return ans;
    }
};