// Simulated Annealing
// Concept -> start from a random point
// have some initial step like 0,0
// move in all 4 directions with this step
// find minimum out of all these directions
// if current points is already the minimum
// step = step / 2
// i.e start looking in more nearby areas
// keep doing this until precision is around 1e-6

class Solution
{
    constexpr static double eps = 1e-6;
    constexpr static double d[5] = {-1, 0, 1, 0, -1};

    double distanceSum(double x, double y, vector<vector<int>> &points)
    {
        double res = 0;
        for (auto &p : points)
            res += sqrt((p[0] - x) * (p[0] - x) + (p[1] - y) * (p[1] - y));
        return res;
    }

public:
    double getMinDistSum(vector<vector<int>> &positions)
    {
        double x = 0, y = 0, step = 100, ans = distanceSum(x, y, positions);

        while (step > eps)
        {
            bool found = false;
            for (int i = 0; i < 4; ++i)
            {
                double nx = x + step * d[i], ny = y + step * d[i + 1];
                double d = distanceSum(nx, ny, positions);

                if (d < ans)
                {
                    x = nx, y = ny;
                    ans = d;
                    found = true;
                    break;
                }
            }
            step /= found ? 1 : 2;
        }

        return ans;
    }
};