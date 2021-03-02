#include <iostream>
#include <vector>
using namespace std;

int rotation_count(int arr[], int n)
{
    // since array is rotated anti-clockwise
    // count = index of smallest element
    // therefore, we have to find the smallest/pivot element

    int start = 0, end = n - 1, mid, prev, next;

    while (start <= end)
    {
        if (arr[start] <= arr[end])
            return start;

        mid = start + (end - start) / 2;
        prev = (mid - 1 + n) % n;
        next = (mid + 1) % n;

        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;
        else if (arr[start] <= arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {5, 1, 2, 3, 4};
    int n = 5;
    cout << rotation_count(arr, n);
    return 0;
}