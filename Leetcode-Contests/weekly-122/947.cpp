// Unite indices not stones
// initially we had islands = unque number of x + unique num of y
// we merge these x, y together and decrease islands
// number of stones that remain = islands
// number of stones that we can remove = total_stones - islands

class Solution
{
    int islands = 0;
    unordered_map<int, int> parent;

    int find(int a)
    {
        if (parent.count(a) == 0)
            parent[a] = a, ++islands;
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b)
    {
        int pa = find(a), pb = find(b);
        if (pa != pb)
            parent[pa] = pb, --islands;
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        for (auto &i : stones)
        {
            unite(i[0], 10001 + i[1]);
        }
        return stones.size() - islands;
    }
};