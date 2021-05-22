// Using simple bool array fast
// USING nth_element in AP : _min + (n-1) * d
class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int n = nums.size();
        int m = l.size();

        vector<bool> res(m, true);
        vector<int> t;

        for (int i = 0; i < m; ++i)
        {
            int start = l[i], end = r[i], k = end - start + 1;

            // invalid
            if (start >= end)
            {
                res[i] = false;
                break;
            }

            int _min = INT_MAX, _max = INT_MIN;
            for (int j = start; j <= end; ++j)
            {
                _min = min(_min, nums[j]);
                _max = max(_max, nums[j]);
            }

            // invalid
            if ((_max - _min) % (k - 1) != 0)
            {
                res[i] = false;
                continue;
            }

            // always valid
            if (_max == _min)
                continue;

            int d = (_max - _min) / (k - 1);
            vector<bool> diffs(k);

            for (int j = start; j <= end; ++j)
            {
                if ((nums[j] - _min) % d != 0 || diffs[(nums[j] - _min) / d] == true)
                {
                    res[i] = false;
                    break;
                }

                diffs[(nums[j] - _min) / d] = true;
            }
        }

        return res;
    }
};

// Brute!
class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int n = nums.size();
        int m = l.size();

        vector<bool> res(m, true);
        vector<int> t;

        for (int i = 0; i < m; ++i)
        {
            int start = l[i], end = r[i], k = end - start + 1;

            if (start >= end)
            {
                res[i] = false;
                break;
            }

            t.clear();
            t.insert(t.begin(), nums.begin() + start, nums.begin() + end + 1);
            sort(t.begin(), t.end());

            int d = t[1] - t[0];
            for (int j = 2; j < t.size(); ++j)
            {
                if (t[j] - t[j - 1] != d)
                {
                    res[i] = false;
                    break;
                }
            }
        }

        return res;
    }
};