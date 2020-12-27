#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        int range_start, range_end;

        sort(intervals.begin(), intervals.end());
        range_start = intervals[0][0];
        range_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            int first = intervals[i][0], second = intervals[i][1];
            if (range_end >= first)
                range_end = max(range_end, second);
            else
            {
                vector<int> t = {range_start, range_end};
                ans.push_back(t);
                range_start = first;
                range_end = second;
            }
        }

        vector<int> t = {range_start, range_end};
        ans.push_back(t);

        return ans;
    }
};