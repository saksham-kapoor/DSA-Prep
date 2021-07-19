// convert x and y to single coordinate to increase speed and decrease space
// xy = n * x + y

class Solution
{
public:
    int nearestExit(vector<vector<char>> &A, vector<int> &e)
    {
        int d[5] = {-1, 0, 1, 0, -1}, m = A.size(), n = A[0].size();
        bool vis[10001] = {};

        queue<int> q;
        q.push(n * e[0] + e[1]);
        vis[n * e[0] + e[1]] = 1;
        int step = 0;

        while (q.size())
        {
            int sz = q.size();

            while (sz--)
            {
                int xy = q.front();
                q.pop();

                int j = xy % n, i = (xy - j) / n;

                // check if this is exit
                if (i + 1 == m || j + 1 == n || i == 0 || j == 0)
                    if (i != e[0] || j != e[1])
                        return step;

                for (int k = 0; k < 4; ++k)
                {
                    int ni = i + d[k], nj = j + d[k + 1];

                    if (ni < m && nj < n && ni >= 0 && nj >= 0 && A[ni][nj] != '+' && vis[n * ni + nj] == 0)
                    {
                        q.push(n * ni + nj);
                        vis[n * ni + nj] = 1;
                    }
                }
            }

            ++step;
        }

        return -1;
    }
};