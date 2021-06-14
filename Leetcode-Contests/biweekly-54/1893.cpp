// LINE SWEEP METHOD
// O(R + N)
class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        int seen[52] = {};

        for (auto &r : ranges)
            ++seen[r[0]], --seen[r[1] + 1];

        for (int i = 1; i < 52; ++i)
            seen[i] += seen[i - 1];

        for (int i = left; i <= right; ++i)
            if (seen[i] == false)
                return false;

        return true;
    }
};

// BRUTE ---> O(R * N)
class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        bool covered[51] = {};

        for (auto &r : ranges)
            for (int i = max(left, r[0]); i <= min(right, r[1]); ++i)
                covered[i] = true;

        for (int i = left; i <= right; ++i)
            if (covered[i] == false)
                return false;

        return true;
    }
};