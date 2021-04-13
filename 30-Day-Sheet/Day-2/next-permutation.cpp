/*

Explanation ->  Traverse array from right to left
                i = n-1 to i >= 1
                find if(A[i-1] < A[i])
                1 3 4 2
                    . .
                  . .
                  3<4
                
                1 3 4 2
                    - - (sorted in decreasing order)
                
                (If No Such Pair [full array is sorted in decreasing order], Reverse the array and return)

                store (i-1) in variable swapI = indexOf(3) = 2
                ===> It means that 3 4 2 is the last permutation of numbers starting from 3
                     Therefore 3 has to be swapped with an element greater [if present] than this for next permutation

                Now we traverse from right to left again
                and we need to find the rightmost element (or the smallest element) greater than A[swapI]

                i = n-1 to i>swapI
                find if(A[i] > A[swapI])
                        swap(A[i], A[swapI])
                    
                        1 4 3 2 (we swapped 3, 4)
                            - -
                            Now 3 2 will be sorting in decreasing order
                            therefore we reverse the array to get the smallest permutation i.e 2 3

                        reverse(A.begin() + swapI + 1, A.end())

                        1 4 2 3 (ans)
                        return

*/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), swapI = -1;
        if (n == 1)
            return;

        for (int i = n - 1; i >= 1; --i)
            if (nums[i - 1] < nums[i])
            {
                swapI = i - 1;
                break;
            }

        if (swapI == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > swapI; --i)
            if (nums[i] > nums[swapI])
            {
                swap(nums[i], nums[swapI]);
                reverse(nums.begin() + swapI + 1, nums.end());
                return;
            }
    }
};