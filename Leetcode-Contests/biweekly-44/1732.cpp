// straight forward O(n)
class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int curr = 0, res = 0;
        for (auto &g : gain)
        {
            curr += g;
            res = max(res, curr);
        }

        return res;
    }
};