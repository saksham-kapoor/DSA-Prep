#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> A, int n, int t)
{
    int s = 0, e = n - 1, m;
    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (t == A[m])
            return m;
        else if (m - 1 >= s && t == A[m - 1])
            return m - 1;
        else if (m + 1 <= e - 1 && t == A[m + 1])
            return m + 1;
        else if (t < A[m])
            e = m - 2;
        else
            s = m + 2;
    }
    return -1;
}

int main()
{
    vector<int> A = {10, 3, 40, 20, 50, 80, 70};
    int key = 40;
    cout << search(A, A.size(), key);
    return 0;
}