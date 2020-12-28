#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    vector<int> B(h + 1);
    while (i <= mid && j <= h)
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];

    while (i <= mid)
        B[k++] = A[i++];

    while (j <= h)
        B[k++] = A[j++];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void mergeSort(vector<int> &A, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int main()
{
    vector<int> A = {9, 8, 4, 5, 6, 7, 5, 4, 8, 5, 1, 2, 5, 6};
    cout << "Given Array : ";
    for (int i : A)
        cout << i << " ";
    cout << "\n";
    mergeSort(A, 0, A.size() - 1);
    cout << "Sorted Array: ";
    for (int i : A)
        cout << i << " ";
}