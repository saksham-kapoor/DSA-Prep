#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDiff(vector<int> A, int n, int m)
{
    int minDiff = INT_MAX;
    sort(A.begin(), A.end());
    for (int i = 0; i + m - 1 < n; i++)
        minDiff = min(minDiff, A[i + m - 1] - A[i]);
    return minDiff;
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int n, m;
        vector<int> A;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        cin >> m;
        cout << minDiff(A, n, m) << "\n";
        T--;
    }
    return 0;
}