/*

Method 1 -> Sort the array (O(NlogN)) then it's pretty easy to count the longest consecutive sequence

Method 2 -> Use unordered set for fast insertion/search

            Concept -> somehow get the starting point of the streak ==> if(nums[i] - 1 is not present in the set)
                       set counter = 1
                       keep finding curr_el + 1 in set and counter++
                       longest = max(longest, count)

            O(N) time average
            O(N) space

*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int longest = 0;
        unordered_set<int> vals(nums.begin(), nums.end()); // store all values o(N) insertion/search

        for (int i = 0; i < nums.size(); ++i)
        {
            if (vals.find(nums[i] - 1) == vals.end())
            {
                // it means that it is the starting point of the sequence4
                int l = 1;
                while (vals.find(nums[i] + l) != vals.end())
                    ++l;
                longest = max(longest, l);
            }
        }

        return longest;
    }
};