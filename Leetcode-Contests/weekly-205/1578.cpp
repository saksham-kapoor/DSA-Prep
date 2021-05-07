// MY GREEDY APPROACH => Local optimum choice can lead to global optimum result
// if there are same consecutive characters, keep track of their costs, and max_cost
// we delete all characters except the one with max_cost to minimise cost!
class Solution
{
public:
    int minCost(string s, vector<int> &cost)
    {
        int min_cost = 0;

        int i = 1;
        while (i <= s.size())
        {
            int m = 0, c = 0;
            while (i < s.size() && s[i] == s[i - 1])
            {
                c += cost[i - 1];
                m = max(m, cost[i - 1]);
                ++i;
            }
            c += cost[i - 1];
            m = max(m, cost[i - 1]);
            min_cost += c - m;
            ++i;
        }

        return min_cost;
    }
};