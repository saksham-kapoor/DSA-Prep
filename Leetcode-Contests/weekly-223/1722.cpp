// CLASSIC UNION FIND WITH PATH COMPRESSION AND UNION BY RANK4
// simple union find => O(n) operations
// union find with path compression or union by rank => O(logN)
// union find with both => O(1)

// so overall complexoty = O(n)
class Solution
{
    int find(int a, int parent[])
    {
        return parent[a] == a ? a : parent[a] = find(parent[a], parent);
    }

    void unite(int a, int b, int p[], int rank[])
    {
        int pa = find(a, p), pb = find(b, p);

        if (pa != pb)
            if (rank[pa] < rank[pb])
                p[pa] = pb;
            else if (rank[pa] > rank[pb])
                p[pb] = pa;
            else
                p[pa] = pb, ++rank[pb];
    }

public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();
        int parent[n], rank[n];
        iota(parent, parent + n, 0);
        memset(rank, 0, sizeof(rank));
        unordered_map<int, vector<int>> mp;
        int res = 0;

        // group indices
        for (auto &s : allowedSwaps)
            unite(s[0], s[1], parent, rank);

        // make map of parent -> vector of children
        for (int i = 0; i < n; ++i)
            mp[find(i, parent)].push_back(i);

        // traverse groups and find common
        for (auto &[p, v] : mp)
        {
            int sz = v.size();
            unordered_multiset<int> st;

            for (int i = 0; i < sz; ++i)
                st.insert(target[v[i]]);

            // match common
            int common = 0;
            for (int i = 0; i < sz; ++i)
            {
                auto it = st.find(source[v[i]]);
                if (it != st.end())
                {
                    ++common;
                    st.erase(it);
                }
            }

            res += sz - common;
        }

        return res;
    }
};