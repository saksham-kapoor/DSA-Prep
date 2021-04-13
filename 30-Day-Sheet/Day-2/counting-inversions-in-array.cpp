/*

Concept - Inversions
          how far (or close) the array is from being sorted.
          If the array is already sorted, then the inversion count is 0
          If the array is sorted in the reverse order, the inversion count is the maximum. 

          OR

          Example
          given array:      8 4 2 1
          inversion array:  3 2 1 0 
                            {inv[i] stores the number of elements towards the right of a[i] < a[i] in array a}
                            8 -> 4, 2, 1 ===> 3
                            4 -> 2, 1 ===> 2
                            2 -> 1 ===> 1
          count of inversions = 3 + 2 + 1 = 6

          OR

          Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

HOW TO CALCULATE -

Method 1 -> Brute Force O(N^2)
            Nested Loop
            Easy

Method 2 -> Merge Sort Method
            Explained in comments

            Why invCount += mid-i+1 while merging?

            2 4 1 3 5

            2 4 1 | 3 5

            2 4 | 1 | 3 | 5

            2 | 4 | 1 | 3 | 5
            \ /
            2 4   1
               \ /
              1 2 4
            
            and so on...

            i -> 0
            mid -> 1

            Here invCount += mid - i + 1
                             1 - 0 + 1
                             2

            As index(1) > index (2) and 1 < 2
            therefore, all elements to the right of 2 will be bigger than 2
            so we include then in the inversion count

            Do a dry run to understand fully
*/

class Solution
{

    long long int merge(long long arr[], long long l, long long mid, long long h)
    {
        long long B[h + 1], i = l, j = mid + 1, k = l, invC = 0;

        // make B by merging arrays in sorted order
        while (i <= mid && j <= h)
            if (arr[i] > arr[j])
            {
                B[k++] = arr[j++];

                // ENTIRE CONCEPT
                invC += mid - i + 1;
            }
            else
                B[k++] = arr[i++];

        // adding remaining elements to B
        while (i <= mid)
            B[k++] = arr[i++];

        // adding remaining elements to B
        while (j <= h)
            B[k++] = arr[j++];

        i = l;

        // comying all elements from B back to A
        while (i <= h)
        {
            arr[i] = B[i];
            i++;
        }

        return invC;
    }

    long long int mergeSort(long long arr[], long long l, long long h)
    {
        long long invC = 0;
        if (l < h)
        {
            long long mid = l + (h - l) / 2;
            invC += mergeSort(arr, l, mid);
            invC += mergeSort(arr, mid + 1, h);
            invC += merge(arr, l, mid, h);
        }
        return invC;
    }

public:
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr, 0, N - 1);
    }
};