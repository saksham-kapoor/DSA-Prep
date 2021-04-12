/*

Method 1 -> Sort the array and find duplicate
            Time: O(NlogN)
            Space: O(1)

Method 2 -> Create Hashmap and find duplicate
            Time: O(N)
            Space: O(N)

Method 3 -> Tortoise and Hare Mathod (OPTIMAL)

            -> Used to get us the entry point of the loop
            -> Here, the duplicate number will be the entry point of the loop
            -> Hence, using this algo here will be most suitable
            
            Create slow = fast = arr[0];
            Now slow makes 1 jump and fast makes 2 jumps till they collide
            They will collide at some value C

            Now place, slow = arr[0]
            Now slow and fast both make 1 jump, till they collide again.
            The value at which they collide gives us the answer.

            Time: O(N)
            Space: O(1)

*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow, fast;
        slow = fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};