// Brute
// O(N*N*M) Solution
class Solution
{

    float calc(int &x1, int &y1, int &x2, int &y2)
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

public:
    vector<int> bestCoordinate(vector<vector<int>> &t, int rad)
    {
        int minX = INT_MAX, maxX = -1, minY = INT_MAX, maxY = -1;
        int ans = 0, _x_ = 0, _y_ = 0;

        for (int i = 0; i < t.size(); ++i)
        {
            int a = t[i][0], b = t[i][1];

            minX = min(minX, a);
            maxX = max(maxX, a);
            minY = min(minY, b);
            maxY = max(maxY, b);
        }

        for (int i = minX; i <= maxX; ++i)
        {
            for (int j = minY; j <= maxY; ++j)
            {

                int q = 0;

                for (int p = 0; p < t.size(); ++p)
                {
                    float d = calc(i, j, t[p][0], t[p][1]);

                    if (d <= (float)rad)
                    {
                        q += (t[p][2] / (1 + (float)d));
                    }
                }

                if (ans < q)
                {
                    ans = q;
                    _x_ = i;
                    _y_ = j;
                }
            }
        }

        if (ans == 0)
            return {0, 0};

        return {_x_, _y_};
    }
};