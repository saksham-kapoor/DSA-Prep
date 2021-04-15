/*

Quesiton -> return elements which occur more than floor(n/3) times

General Idea -> Can we calculate how many elements at max can be there?
                if total elements = n
                let element 'A' occur n/3 + 1 times
                let element 'B' occur n/3 + 1 times

                adding
                2n/3 + 2 times

                subtracting from n
                < n/3

                Therefore, we can have at max 2 elements

                Can we modify Moore's algorithm to suit our needs?
                Yes.
 
*/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return nums;

        vector<int> ans;
        int el1 = -1, el2 = -1, c1 = 0, c2 = 0;

        for (int i = 0; i < n; ++i)
            if (el1 == nums[i])
                ++c1;
            else if (el2 == nums[i])
                ++c2;
            else if (c1 == 0)
            {
                el1 = nums[i];
                c1 = 1;
            }
            else if (c2 == 0)
            {
                el2 = nums[i];
                c2 = 1;
            }
            else
            {
                --c1;
                --c2;
            }

        c1 = c2 = 0;
        for (int i = 0; i < n; ++i)
            if (nums[i] == el1)
                ++c1;
            else if (nums[i] == el2)
                ++c2;

        if (c1 > n / 3)
            ans.push_back(el1);
        if (c2 > n / 3)
            ans.push_back(el2);

        return ans;
    }
};

// Hash Map Method

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         vector<int> ans;
//         unordered_map<int, int> fz;
//         int n = nums.size();

//         for(int i=0; i<n; ++i) {
//             if(fz[nums[i]] == n/3) {
//                 ans.push_back(nums[i]);
//                 fz[nums[i]] = -n;
//             } else {
//                 ++fz[nums[i]];
//             }
//         }

//         return ans;
//     }
// };