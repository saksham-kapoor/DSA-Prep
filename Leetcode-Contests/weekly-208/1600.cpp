// standard DFS problem!

class ThroneInheritance
{
    unordered_set<string> dead;
    unordered_map<string, vector<string>> kids;
    string king;

    void dfs(string node, vector<string> &ans)
    {
        if (dead.find(node) == dead.end())
            ans.push_back(node);

        for (auto &i : kids[node])
        {
            dfs(i, ans);
        }
    }

public:
    ThroneInheritance(string kingName)
    {
        king = kingName;
    }

    void birth(string parentName, string childName)
    {
        kids[parentName].push_back(childName); // O(1) avg
    }

    void death(string name)
    {
        dead.insert(name); // o(1) avg
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> ans;

        dfs(king, ans);

        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */