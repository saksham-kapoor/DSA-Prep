#include <iostream>
using namespace std;

class Solution
{
    int maxFromArray, sumOfArray;

public:
    int assignMaxAndSum(int arr[], int n)
    {
        int max = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
                max = arr[i];
            sum += arr[i];
        }
        maxFromArray = max;
        sumOfArray = sum;
    }

    bool isValid(int arr[], int n, int m, int mx)
    {
        int count = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mx)
            {
                count++;
                sum = arr[i];

                if (count > m)
                    return 0;
            }
        }
        return 1;
    }

    int findPages(int arr[], int n, int m)
    {
        assignMaxAndSum(arr, n);
        int start = maxFromArray, end = sumOfArray, mid, res = -1;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (isValid(arr, n, m, mid))
            {
                res = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return res;
    }
};