// AMAZING, MUST REVISE!

class Solution
{
public:
    int minMoves(vector<int> &nums, int k)
    {
        if (k == 1)
            return 0;

        int n = nums.size(), prefix[n + 1];
        prefix[0] = 0;

        vector<int> pos;
        for (int i = 0; i < n; ++i)
            if (nums[i] == 1)
                pos.push_back(i - pos.size());

        partial_sum(pos.begin(), pos.end(), prefix + 1);

        int res = INT_MAX;

        // create sliding window of size k
        for (int l = 0, r = k - 1; r < pos.size(); ++l, ++r)
        {
            int mid = (l + r) / 2;
            int right = prefix[l + k] - prefix[mid + 1];
            int left = prefix[mid] - prefix[l];
            int extra = k & 1 ? 0 : pos[mid];

            res = min(res, right - left - extra);
        }

        return res;
    }
};