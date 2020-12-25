#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> A)
{
    for (auto i : A)
        cout << i << " ";
    cout << "\n";
}

void cyclicRotateByOne(vector<int> &A)
{
    int n = A.size();
    int last = A[n - 1];
    for (int i = n - 1; i > 0; i--)
        A[i] = A[i - 1];
    A[0] = last;
}

int main()
{
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cyclicRotateByOne(A);
    printArr(A);
    return 0;
}