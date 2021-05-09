class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        array<int, 101> intervals = {};

        for (auto &i : logs)
        {
            intervals[i[0] - 1950] += 1;
            intervals[i[1] - 1950] -= 1;
        }

        for (int i = 1; i < intervals.size(); ++i)
        {
            intervals[i] += intervals[i - 1];
        }

        return distance(intervals.begin(), max_element(intervals.begin(), intervals.end())) + 1950;
    }
};
