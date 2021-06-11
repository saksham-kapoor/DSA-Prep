class Solution
{
    int find(int a, int parent[])
    {
        return parent[a] == a ? a : parent[a] = find(parent[a], parent);
    }

    void unite(int a, int b, int parent[], int rank[])
    {
        int pa = find(a, parent), pb = find(b, parent);
        if (pa != pb)
        {
            if (rank[pa] < rank[pb])
                parent[pa] = pb;
            else if (rank[pa] > rank[pb])
                parent[pb] = pa;
            else
                parent[pa] = pb, ++rank[pb];
        }
    }

    bool is_connected(int a, int b, int parent[])
    {
        return find(a, parent) == find(b, parent) ? true : false;
    }

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edges, vector<vector<int>> &q)
    {
        auto comp = [](auto &a, auto &b)
        { return a[2] < b[2]; };
        sort(edges.begin(), edges.end(), comp);

        // adding index to queries before sorting
        for (int i = 0; i < q.size(); ++i)
            q[i].push_back(i);
        sort(q.begin(), q.end(), comp);

        // union find
        int parent[n], rank[n];
        iota(parent, parent + n, 0);
        memset(rank, 0, sizeof(rank));

        int j = 0;
        vector<bool> res(q.size());

        for (int i = 0; i < q.size(); ++i)
        {
            int maxwt = q[i][2], idx = q[i][3];
            for (; j < edges.size() && edges[j][2] < maxwt; ++j)
            {
                unite(edges[j][0], edges[j][1], parent, rank);
            }
            res[idx] = is_connected(q[i][0], q[i][1], parent) ? true : false;
        }

        return res;
    }
};