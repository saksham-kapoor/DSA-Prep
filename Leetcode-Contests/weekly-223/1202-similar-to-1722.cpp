class Solution
{
    int find(int a, int p[])
    {
        return p[a] == a ? a : p[a] = find(p[a], p);
    }

    void unite(int a, int b, int p[], int r[])
    {
        int pa = find(a, p), pb = find(b, p);
        if (pa != pb)
            if (r[pa] < r[pb])
                p[pa] = pb;
            else if (r[pa] > r[pb])
                p[pb] = pa;
            else
                p[pa] = pb, ++r[pb];
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size(), parent[n], rank[n];
        memset(rank, 0, sizeof(rank));
        iota(parent, parent + n, 0);

        // unite pairs
        for (auto &p : pairs)
            unite(p[0], p[1], parent, rank);

        // group indices
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i)
            mp[find(i, parent)].push_back(i);

        //construct string
        for (auto &[p, v] : mp)
        {
            // count sort
            array<int, 26> fz = {};
            for (auto &i : v)
                ++fz[s[i] - 'a'];

            int f = 0;
            for (auto &i : v)
            {
                while (fz[f] == 0)
                    ++f;
                s[i] = f + 'a';
                --fz[f];
            }
        }

        return s;
    }
};