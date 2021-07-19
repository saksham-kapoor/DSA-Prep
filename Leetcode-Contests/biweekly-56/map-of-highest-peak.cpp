// BFS FROM LOWER VALUE CELLS

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &A)
    {
        int m = A.size(), n = A[0].size(), d[5] = {-1, 0, 1, 0, -1};
        queue<int> q;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (A[i][j] == 1)
                    q.push(n * i + j), A[i][j] = 0;
                else
                    A[i][j] = -1;

        while (!q.empty())
        {
            int sz = q.size();

            // process all cells of same value
            while (sz--)
            {
                int xy = q.front();
                q.pop();

                int y = xy % n, x = (xy - y) / n;

                // traverse adj cells and increment
                for (int i = 0; i < 4; ++i)
                {
                    int new_x = x + d[i], new_y = y + d[i + 1];

                    if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n && A[new_x][new_y] == -1)
                    {
                        A[new_x][new_y] = A[x][y] + 1;
                        q.push(new_x * n + new_y);
                    }
                }
            }
        }

        return A;
    }
};