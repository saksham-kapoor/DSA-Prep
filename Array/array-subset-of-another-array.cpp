#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Concept - All elements of B must be in A

// O(log{N})
int BinarySearch(vector<int> A, int l, int h, int k)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (A[mid] == k)
            return 1;
        else if (A[mid] > k)
            return BinarySearch(A, l, mid - 1, k);
        else
            return BinarySearch(A, mid + 1, h, k);
    }
    return 0;
}

// Binary Search Method - O(mlogm) sort + O(nlogm) traveral + search = O({m+n}logm)
void checkSubset_UsingBinarySearch(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    for (auto i : B)
    {
        int found = BinarySearch(A, 0, A.size() - 1, i);
        if (found != 1)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

// O(m + n) time, O(m) space
void checkSubset_UsingSets(vector<int> A, vector<int> B)
{
    unordered_set<int> A_Elements;
    for (auto i : A)
        A_Elements.insert(i);

    for (auto i : B)
        if (A_Elements.find(i) == A_Elements.end())
        {
            cout << "No"
                 << "\n";
            return;
        }
    cout << "Yes"
         << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int m, n;
        cin >> m >> n;
        vector<int> A, B;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            B.push_back(x);
        }
        if (n > m)
            cout << "No";
        else
            checkSubset_UsingBinarySearch(A, B);
        T--;
    }
}