#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> vals;
        int maxLength = 1;

        for (auto i : nums)
            vals.insert(i);

        for (auto i : nums)
            if (vals.find(i - 1) == vals.end())
            {
                // it is the first element in the sequence
                int k = 1;
                while (vals.find(i + k) != vals.end())
                    k++;

                maxLength = max(maxLength, k);
            }

        return maxLength;
    }
};