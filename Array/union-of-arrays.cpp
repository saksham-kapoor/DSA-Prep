#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void printUnion(vector<int> A, vector<int> B)
{
    vector<int> C(pow(10, 5), 0);
    for (int i = 0; i < A.size(); i++)
    {
        C[A[i]]++;
    }
    for (int i = 0; i < B.size(); i++)
    {
        C[B[i]]++;
    }
    int count = 0;
    for (int i = 0; i < C.size(); i++)
    {
        if (C[i] != 0)
        {
            count++;
        }
    }
    cout << count << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int n, m;
        cin >> n >> m;
        vector<int> A, B;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            B.push_back(x);
        }
        printUnion(A, B);
        T--;
    }
    return 0;
}