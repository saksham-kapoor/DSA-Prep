#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool isValid(vector<int> A, int N, int C, int mid)
{
    int nC = 1;
    int lastAccepted = 0;
    for (int i = 1; i < N; i++)
    {
        if (A[i] - A[lastAccepted] >= mid)
        {
            lastAccepted = i;
            nC++;
        }
    }
    if (nC < C)
        return false;
    return true;
}

// A - stall locations, N - # of stalls, C - # of cows
int largestMinDistance(vector<int> A, int N, int C)
{
    int largestMinDistance = -1;
    sort(A.begin(), A.end());

    int start = 0, end = A[N - 1] - A[0];
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(A, N, C, mid))
        {
            largestMinDistance = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return largestMinDistance;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        cout << largestMinDistance(v, n, c) << "\n";
    }
    return 0;
}