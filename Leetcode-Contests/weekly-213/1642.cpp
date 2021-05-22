class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> mn;
        int res = 0;

        while (bricks >= 0 && res + 1 < heights.size())
        {

            int d = heights[res + 1] - heights[res];
            if (d <= 0)
            {
                res++;
                continue;
            }

            mn.push(d);

            if (mn.size() > ladders)
            {
                bricks -= mn.top();
                mn.pop();

                if (bricks < 0)
                    return res;
            }

            ++res;
        }

        return res;
    }
};