class Solution
{
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        vector<int> res(tasks.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> avail, unavail;

        // avail -> wt, i
        // time, server i

        // nlogn time
        for (int i = 0; i < servers.size(); ++i)
        {
            avail.emplace(servers[i], i);
        }

        int i = 0;
        for (int t = 0; i < tasks.size(); ++t)
        {
            while (unavail.size() && unavail.top().first <= t)
            {
                avail.emplace(servers[unavail.top().second], unavail.top().second);
                unavail.pop();
            }

            if (avail.size() == 0)
            {
                t = unavail.top().first - 1;
                continue;
            }

            while (i <= t && i < tasks.size() && avail.size())
            {
                res[i] = avail.top().second; // assign task
                unavail.emplace(t + tasks[i], avail.top().second);
                avail.pop();
                ++i;
            }
        }

        return res;
    }
};