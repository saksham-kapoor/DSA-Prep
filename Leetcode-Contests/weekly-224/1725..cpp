// 1 pass method
// calculate size + count simult.
class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rect)
    {
        int mxsz = 0, cnt = 0;

        for (auto &r : rect)
        {
            int sz = min(r[0], r[1]);
            if (sz > mxsz)
                mxsz = sz, cnt = 1;
            else if (mxsz == sz)
                ++cnt;
        }

        return cnt;
    }
};

// 2 pass method
// pass 1 -> find max rectangle size
// pass 2 -> find number of rectangles with 'max size'
class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rect)
    {
        int res = 0, cnt = 0;

        for (auto &r : rect)
            res = max(res, min(r[0], r[1]));

        for (auto &r : rect)
            if (min(r[0], r[1]) == res)
                ++cnt;

        return cnt;
    }
};