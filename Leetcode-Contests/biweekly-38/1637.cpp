// Using a set - ordered, so no explicit sorting is required, lil bit faster than normal sort
class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        set<int> st;
        for (auto &p : points)
            st.insert(p[0]);

        int mx = 0;

        // next(it) gives iterator to next position
        // prev(it) gives iterator to previous position
        for (auto it = next(st.begin()); it != st.end(); ++it)
        {
            mx = max(mx, *it - *prev(it));
        }

        return mx;
    }
};

// Simple sorting - okayish
class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int mx = INT_MIN;

        for (int i = 1; i < (int)points.size(); ++i)
        {
            mx = max(mx, points[i][0] - points[i - 1][0]);
        }

        return mx;
    }
};