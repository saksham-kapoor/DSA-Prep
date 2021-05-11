class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        vector<int> ans(queries.size());

        // sort intervals with increasing starting point
        sort(intervals.begin(), intervals.end());

        // save indices of queries
        vector<pair<int, int>> _queries(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            _queries[i] = {queries[i], i};
        }

        // sort queries with increasing numbers
        sort(_queries.begin(), _queries.end());

        int i = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for (auto &query : _queries)
        {
            int q = query.first, idx = query.second;

            // storing {size, end} of interval
            while (i < intervals.size() && intervals[i][0] <= q)
            {
                min_heap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                ++i;
            }

            bool flag = true;

            while (!min_heap.empty())
            {
                auto p = min_heap.top();

                if (q <= p.second)
                {
                    ans[idx] = p.first;
                    flag = false;
                    break;
                }
                else
                {
                    min_heap.pop();
                }
            }

            if (min_heap.empty() && flag)
                ans[idx] = -1;
        }

        return ans;
    }
};