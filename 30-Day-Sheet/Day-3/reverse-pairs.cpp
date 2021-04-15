/*

What is a reversePair?
--> i<j
--> val[i] > 2*val[j]

Amazing Question-
Please read -> https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22

*/

class Solution
{

    int _mergeSort(vector<int> &nums, int l, int h)
    {
        int count = 0;
        if (l < h)
        {
            int m = l + (h - l) / 2;
            count = _mergeSort(nums, l, m) + _mergeSort(nums, m + 1, h);

            // merge
            int i = l, p = m + 1;

            // counting the reverse pairs
            // this algo works assuming the the 2 halves are sorted
            // we sort them below this block
            while (i <= m)
            {
                while (p <= h && nums[i] > 2 * (long)nums[p])
                    ++p;
                count += p - (m + 1);
                ++i;
            }

            // merges the array in place
            // average o(n), worst o(nlogn)
            // in sorted order
            // [first, last)
            // [first, mid), [mid, last)
            inplace_merge(nums.begin() + l, nums.begin() + m + 1, nums.begin() + h + 1);
        }
        return count;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return _mergeSort(nums, 0, nums.size() - 1);
    }
};