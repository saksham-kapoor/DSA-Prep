// RECURSION + MEMO
class Solution
{
    vector<int> t;

    int solveHelper(vector<int> &nums, int target)
    {
        if (t[target] != -1)
            return t[target];

        int res = 0;

        for (int i = 0; i < nums.size(); ++i)
            if (target >= nums[i])
            {
                res += solveHelper(nums, target - nums[i]);
            }

        return t[target] = res;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        t.resize(target + 1, -1);
        t[0] = 1;
        return solveHelper(nums, target);
    }
};

// RECURSIVE SOLUTION
// class Solution {
//     int solveHelper(vector<int>&nums, int target) {
//         int ans = 0;
//         if(target == 0) {
//             return 1; // base case
//         } else if(target > 0) {
//             // recursion case
//             for(int i=0; i<nums.size(); ++i) {
//                 ans += solveHelper(nums, target - nums[i]);
//             }
//         }
//         return ans;
//     }

// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         return solveHelper(nums, target);
//     }
// };