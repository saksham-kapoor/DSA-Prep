// amazing question
// extremely easy if one is able to relate this to graphs and adjacency lists
// BFS

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &p)
    {
        int n = p.size() + 1, k = 0;
        vector<int> res(n);
        unordered_map<int, vector<int>> mp;

        // adj list
        for (auto &i : p)
        {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }

        int start;
        for (auto &[n, v] : mp)
            if (v.size() == 1)
            {
                start = n;
                break;
            }

        queue<int> q;
        q.push(start);
        unordered_set<int> vis;

        // bfs
        while (q.size())
        {
            int node = q.front();
            q.pop();

            if (vis.find(node) != vis.end())
                continue;
            vis.insert(node);
            res[k++] = node;

            for (int i = 0; i < mp[node].size(); ++i)
                q.push(mp[node][i]);
        }

        return res;
    }
};