/*

Here we have to find the maximum number of meetings that can be conducted in a single room such that no mtwo meetings overlap
In other words, we select some meetings and ignore others

So, this is an activity selection problem.
Now the question here is that how to accommodate maximum meetings.

We are given the starting and ending time of each meeting.

GREEDY ALGORITHM!
1. We sort the meetings in increasing order of ending times,
   i.e the meetings which end first, come first in the sorted order.

2. Now selected first meeting.

3. Keep traversing the meetings array and select next meeting whose starting time > ending time of previously selected meeting.

[repeat this process till end of list]

*/

#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> schedule;

        for (int i = 0; i < n; ++i)
        {
            schedule.emplace_back(start[i], end[i]);
        }

        sort(schedule.begin(), schedule.end(), comp);

        int max_meetings = 1, end_time = schedule[0].second; // first meeting in list will always be selected

        for (int i = 1; i < n; ++i)
        {
            if (schedule[i].first > end_time)
            {
                ++max_meetings;
                end_time = schedule[i].second;
            }
        }

        return max_meetings;
    }
};
