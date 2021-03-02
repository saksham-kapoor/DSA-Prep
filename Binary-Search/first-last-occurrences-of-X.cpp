#include <iostream>
#include <vector>
using namespace std;

void occurrence_binary_search(int A[], int low, int high, int target)
{
    int mid, first = -1, last = -1;
    int start = low, end = high;
    // we are looking for the first occurrence
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (target == A[mid])
        {
            first = mid;
            end = mid - 1;
        }
        else if (target < A[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    start = low, end = high;
    // we are looking for the last occurrence
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (target == A[mid])
        {
            last = mid;
            start = mid + 1;
        }
        else if (target < A[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    if (first == -1)
        cout << -1 << "\n";
    else
        cout << first << " " << last << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int n, x;
        cin >> n >> x;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        occurrence_binary_search(A, 0, n - 1, x);
        T--;
    }
    return 0;
}