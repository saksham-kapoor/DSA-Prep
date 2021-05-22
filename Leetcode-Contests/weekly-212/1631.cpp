class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        int dir[5] = {-1, 0, 1, 0, -1};

        // initialize efforts
        int efforts[m][n];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                efforts[i][j] = INT_MAX;
            }
        }

        efforts[0][0] = 0;

        // min heap to give us minimum distance on top
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({0, 0, 0}); // distance, r, c

        while (pq.size())
        {
            int curr_effort = pq.top()[0], r = pq.top()[1], c = pq.top()[2];
            pq.pop();

            if (r == m - 1 && c == n - 1)
                return curr_effort;

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dir[i], nc = c + dir[i + 1];

                // invalid positions
                if (nr < 0 || nr == m || nc < 0 || nc == n)
                    continue;

                // new effort to reach valid position
                int new_effort = max(curr_effort, abs(heights[nr][nc] - heights[r][c]));

                // efforts[nr][nc] stores prev effort required to reach there,
                // we update it if we can now reach there in less effort
                if (new_effort < efforts[nr][nc])
                {
                    efforts[nr][nc] = new_effort;
                    pq.push({new_effort, nr, nc});
                }
            }
        }

        return -1;
    }
};