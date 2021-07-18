class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string rk, string rv)
    {
        int res = 0;

        for (auto &i : items)
        {
            if (rk == "type" && i[0] == rv || rk == "color" && i[1] == rv || rk == "name" && i[2] == rv)
                ++res;
        }

        return res;
    }
};