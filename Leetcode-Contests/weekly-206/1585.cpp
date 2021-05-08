// DRY RUN WITH 787 AND 778 FOR BETTER UNDERSTANDING
class Solution
{
public:
    bool isTransformable(string s, string t)
    {
        vector<int> pos[10];
        for (int i = s.size() - 1; i >= 0; --i)
        {
            pos[s[i] - '0'].push_back(i);
        }

        for (auto &c : t)
        {
            int key = c - '0';
            if (pos[key].empty())
                return false;

            for (int i = 0; i < key; ++i)
            {
                if (pos[i].size() && pos[i].back() < pos[key].back())
                    return false;
            }

            pos[key].pop_back();
        }

        return true;
    }
};