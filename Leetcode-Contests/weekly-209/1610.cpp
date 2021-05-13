class Solution
{
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
    {
        int x = location[0], y = location[1], coinc = 0, ans = 0;
        double pi = acos(-1.0);
        vector<float> angles;

        for (auto &p : points)
        {
            if (x == p[0] && y == p[1])
                coinc++;
            else
            {
                float a = atan2(p[1] - y, p[0] - x) * 180 / pi;
                if (a < 0)
                    a += 360;
                angles.push_back(a);
            }
        }

        sort(angles.begin(), angles.end());
        int n = angles.size();

        for (int i = 0; i < n - 1; ++i)
        {
            angles.push_back(angles[i] + 360);
        }

        // sliding window
        int start = 0;
        for (int i = 0; i < angles.size(); ++i)
        {
            if (angles[i] - angles[start] > angle)
            {
                start++;
            }
            ans = max(ans, i - start + 1);
        }

        return coinc + ans;
    }
};