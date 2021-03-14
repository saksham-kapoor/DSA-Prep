class Solution
{
    int findPos(vector<int> &p, int index, int k)
    {
        if (p.size() == 1)
            return p[0];
        int to_delete = (index + k) % p.size();
        p.erase(p.begin() + to_delete);
        return findPos(p, to_delete, k);
    }

public:
    int safePos(int n, int k)
    {
        // init
        vector<int> p;
        for (int i = 1; i <= n; i++)
            p.push_back(i);

        k--;
        return findPos(p, 0, k);
    }
};