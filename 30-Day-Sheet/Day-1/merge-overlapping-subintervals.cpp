/*

General Algo => Sort the intervals array as it won't be possible otherwise

                Concept -
                Two intervals are merged only when start of a latter interval <= end of the former interval
                i.e a new interval starts before one finishes (hence, overlapping)

                2 cases -
                1. [1,4], [3, 6]

                    i.e
                    1 2 3 4 5 6
                    .     .
                        .     .
                    
                    new interval = [1,6]
                2. [1, 6], [2, 4]

                    i.e
                    1 2 3 4 5 6
                    .         .
                      .   .

                    new interval = [1,6]

                Therefore, if overlapping
                start of new interval = start of former interval
                end of new interval = max(end of former interval, end of latter interval)

*/

#include <vector>
#include <algorithm>
using namespace std;

// more concise solution
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
            return intervals;

        // sorting intervals array
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
            if (intervals[i][0] <= ans.back()[1])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);

        return ans;
    }
};

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
            return intervals;

        // sorting intervals array
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int range_start = intervals[0][0];
        int range_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            int start = intervals[i][0], end = intervals[i][1];
            if (start <= range_end)
                range_end = max(range_end, end);
            else
            {
                vector<int> t = {range_start, range_end};
                ans.push_back(t);
                range_start = start;
                range_end = end;
            }
        }

        vector<int> t = {range_start, range_end};
        ans.push_back(t);

        return ans;
    }
};