/*

Method 1 -> O(N^4) solution [Brute]

Method 2 -> Sort the array
            O(N^3 * logN) -> choose 3 elements using nested loops and apply binary search on remaining array

Method 3 -> Sort the array, pick two elements, apply 2 pointer method in the remaining array
            O(N^2 * N) + NlogN
            O[(nested loop) * (2 pointer method)]   

            target = 17

            1  2  3  4  5  6  7  8  9
            c        c  |           |
            c        c  |     |

            the 'j' loop should skip over duplicates

*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n <= 3)
            return ans;

        // sort the array
        sort(nums.begin(), nums.end());

        int i, j, left, right;
        for (i = 0; i < n - 1; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                int new_target = target - nums[i] - nums[j];

                left = j + 1;
                right = n - 1;

                while (left < right)
                {
                    int two_sum = nums[left] + nums[right];

                    if (two_sum < new_target)
                        ++left;
                    else if (two_sum > new_target)
                        --right;
                    else
                    {
                        vector<int> new_ans(4);
                        new_ans[0] = nums[i];
                        new_ans[1] = nums[j];
                        new_ans[2] = nums[left];
                        new_ans[3] = nums[right];

                        ans.push_back(new_ans);

                        // ignore duplicates @left
                        while (left < right && nums[left] == new_ans[2])
                            ++left;

                        // ignore duplicates @right
                        while (left < right && nums[right] == new_ans[3])
                            --right;
                    }
                }

                // ignore duplicates @j
                while (j + 1 < n && nums[j] == nums[j + 1])
                    ++j;
            }

            // ignore duplicates @i
            while (i + 1 < n - 1 && nums[i] == nums[i + 1])
                ++i;
        }

        return ans;
    }
};