/*

Observations -> 
1. if sum of all costs > sum of all gas, no possible solution, else solution.
2. if A cannot reach some point B (B is the first point A cannot reach), then no point between A & B
   can reach B.

*/

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0, start = 0, tank = 0;

        for (int i = 0; i < (int)gas.size(); ++i)
        {
            // for observation 1
            total += gas[i] - cost[i];

            // for observation 2
            tank += gas[i] - cost[i];
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }

        if (total < 0)
            return -1;
        return start;
    }
};