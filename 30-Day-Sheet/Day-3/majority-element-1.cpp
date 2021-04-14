/*

Method 1 -> Simple Approach would be to maintain a fz hashmap
            return the element which appears more than n/2 times
            
            O(n) time
            O(n) space
            
Method 2 -> Another Approach is to return the element which comes at n/2th index in the sorted array
            
            Why?
            as it's frequency is greater than n/2
            so it won't accommodate in either half and will always pass through the middle element
            in sorted array
          
            average O(n) time
            O(1) space
            
Method 3 -> Moore Voting Algorithm
            https://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html

*/

// Method 3 => Moore's Voting Algorithm
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1, major_element = nums[0];

        for (int i = 1; i < nums.size(); ++i)
            if (count == 0)
            {
                major_element = nums[i];
                ++count;
            }
            else if (nums[i] == major_element)
                ++count;
            else
                --count;

        return major_element;
    }
};

// Method 2
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
//         return nums[nums.size()/2];
//     }
// };