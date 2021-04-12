/*

Method 1 -> With Extra Space
            Create a new array with size m+n
            Copy elements from arr1 and arr2 to new array in sorted order

Method 2 -> Sorting 1 array each time we make a swap
            A = [1, 5, 10]
            B = [2, 3, 4]

            A = [1, 2, 10]
            B = [5, 3, 4] => Sort This => B [3, 4, 5]

            A = [1, 2, 3]
            B = [10, 4, 5] => Sort This => B [4, 5, 10]

            O(n*m) time, O(1) space

Method 3 -> Gap Method
            Explained in code
            Intuition Unknown

            A = [1, 5, 9]
            B = [2, 3, 4]

            gap = 6/2 = 3
            
            visualize it as
            [1, 5, 9] [2, 3, 4]
    index    0  1  2   3  4  5
             i         j
                i         j
                   i         j

            swap if A[i] < A[j] ------> but we have 2 arrays instead of one so we do it a little differently, however concept is same

            gap = gap / 2;
            and so on.

            Time : O(Nlog(N)), Space : O(1)

*/

class Solution
{
public:
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int N = n + m;
        int gap = N / 2 + N % 2; // gap = ceil(n/2)

        while (gap > 0)
        {
            int i, j;
            i = 0;
            j = gap;

            while (j < N)
            {
                if (i < n && j < n)
                {
                    if (arr1[i] > arr1[j])
                        swap(arr1[i], arr1[j]);
                }
                else if (i < n && j >= n)
                {
                    if (arr1[i] > arr2[j - n])
                        swap(arr1[i], arr2[j - n]);
                }
                else if (arr2[i - n] > arr2[j - n])
                    swap(arr2[i - n], arr2[j - n]);

                i++;
                j++;
            }

            if (gap == 1)
                return;
            gap = gap / 2 + gap % 2;
        }
    }
};