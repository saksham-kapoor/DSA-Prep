class Solution
{
    int n;
    vector<pair<int, int>> lanes;
    vector<vector<int>> t;
    vector<int> ob;

    int solve(int lane, int point)
    {
        // end condition
        if (point == n)
            return t[lane][point] = 0;

        if (t[lane][point] != -1)
            return t[lane][point];

        if (lane == ob[point + 1])
        {
            // now possible lanes
            int l1 = lanes[lane].first, l2 = lanes[lane].second;

            t[lane][point] = INT_MAX;
            if (ob[point] != l1)
                t[lane][point] = min(t[lane][point], solve(l1, point));

            if (ob[point] != l2)
                t[lane][point] = min(t[lane][point], solve(l2, point));

            t[lane][point] += 1;
        }
        else
            t[lane][point] = solve(lane, point + 1);

        return t[lane][point];
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        lanes.resize(4);
        lanes[1] = {2, 3};
        lanes[2] = {1, 3};
        lanes[3] = {1, 2};
        n = obstacles.size() - 1;
        ob = obstacles;

        // memo
        t.resize(4, vector<int>(n + 1, -1));

        return solve(2, 0);
    }
};