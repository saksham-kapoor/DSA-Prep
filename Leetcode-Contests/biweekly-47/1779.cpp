// Elements which are only required in the loop can be declared in the 'for' statement
// Improves readability

class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int res = -1;

        for (int i = 0, smallest_distance = INT_MAX; i < points.size(); ++i)
        {
            int dx = x - points[i][0], dy = y - points[i][1];
            if (dx * dy == 0 && abs(dx + dy) < smallest_distance)
            {
                smallest_distance = abs(dx + dy);
                res = i;
            }
        }

        return res;
    }
};