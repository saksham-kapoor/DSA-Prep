// 2 pointer method
// trace on paper to get a better understanding
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return n;

        // maintain 2 pointers
        int pos = 1;

        for (int i = 1; i < n; ++i)     // traverse entire vector
            if (nums[i] != nums[i - 1]) // gives true on unique elements in sorted array
                nums[pos++] = nums[i];  // copy them to the 'pos' index

        return pos; // will return the length of the new array
    }
};

// Brute Force Solution
// Deleting the unwanted elements
// O(N^2)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 1;

        while (i < nums.size())
        {
            if (nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i);
            }
            else
            {
                ++i;
            }
        }

        return nums.size();
    }
};