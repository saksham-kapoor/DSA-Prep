#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &A, int l, int h)
{
    int x = A[h];
    int i = h;
    while (i > l)
    {
        swap(A[i], A[i - 1]);
        i--;
    }
    A[i] = x;
}

void rearrangePreserveOrder(vector<int> &A)
{
    int n = A.size(), l = 0, m = 1;
    while (m < n)
        if ((l % 2 == 0 && A[l] < 0) || (l % 2 != 0 && A[l] >= 0))
        {
            // if element is not out of space
            l++;
            m = l + 1;
        }
        else
        {
            if ((A[l] > 0 && A[m] < 0) || (A[l] < 0 && A[m] > 0))
                rotate(A, l, m);
            m++;
        }
}

void rearrange(vector<int> &A)
{
    int n = A.size(), l = 0, m = 1;
    while (m < n)
        if ((A[l] < 0 && l % 2 == 0) || (A[l] > 0 && l % 2 != 0))
        {
            l++;
            m = l + 1;
        }
        else
        {
            if (A[l] > 0 && A[m] < 0 || A[l] < 0 && A[m] > 0)
                swap(A[l], A[m]);
            m++;
        }
}

void printArr(vector<int> A)
{
    for (int i : A)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    vector<int> A = {-5, 3, 4, 5, -6, -2, 8, 9, -1, -4};
    cout << "Original Array: ";
    printArr(A);
    // rearrangePreserveOrder(A); // O(n2) worst
    rearrange(A); // O(n) - Order is not preserved
    cout << "New Array: ";
    printArr(A);
}