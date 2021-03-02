#include <iostream>
#include <vector>
using namespace std;

int BS(int arr[], int s, int e, int t)
{
    while (s <= e)
    {
        int m = s + (e - s) / 2;

        if (t == arr[m])
            return m;
        else if (t < arr[m])
            e = m - 1;
        else
            s = m + 1;
    }
    return -1;
}

int search_in_rotated_sorted(int arr[], int n, int target)
{
    // since array is rotated anti-clockwise
    // count = index of smallest element
    // therefore, we have to find the smallest/pivot element

    int start = 0, end = n - 1, mid, prev, next, pivot = -1;

    while (start <= end)
    {
        if (arr[start] <= arr[end])
        {
            pivot = start;
            break;
        }

        mid = start + (end - start) / 2;
        prev = (mid - 1 + n) % n;
        next = (mid + 1) % n;

        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
        {
            pivot = mid;
            break;
        }
        else if (arr[start] <= arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    // Now we can divide the array in two parts using pivot element
    if (target == arr[pivot])
        return pivot;
    else if (target >= arr[0] && target <= arr[(pivot - 1 + n) % n])
        return BS(arr, 0, (pivot - 1 + n) % n, target);
    else
        return BS(arr, (pivot + 1) % n, n - 1, target);
}

int main()
{
    int arr[] = {1};
    int n = 1;
    cout << search_in_rotated_sorted(arr, n, 0);
    return 0;
}