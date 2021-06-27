// Simple 1 pass solution

class Solution
{
public:
    int sumOfUnique(vector<int> &A)
    {
        int vis[101] = {}, res = 0;

        for (auto &i : A)
        {
            res += vis[i] == 0 ? i : vis[i] == 1 ? -i
                                                 : 0;
            ++vis[i];
        }

        return res;
    }
};