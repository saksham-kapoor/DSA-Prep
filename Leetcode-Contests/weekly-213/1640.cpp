// Sheer elegance

class Solution
{
public:
    bool canFormArray(vector<int> &A, vector<vector<int>> &p)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < p.size(); ++i)
            mp[p[i][0]] = i;

        for (int i = 0; i < A.size();)
        {
            auto it = mp.find(A[i]);

            if (it == mp.end())
                return false;

            int size = p[it->second].size();
            for (int j = 0; j < size && i < A.size(); ++j, ++i)
            {
                if (A[i] != p[it->second][j])
                    return false;
            }
        }

        return true;
    }
};