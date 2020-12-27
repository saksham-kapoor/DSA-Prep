#include <iostream>
#include <math.h>
using namespace std;

void printArr(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}

void merge(int A[], int B[], int n, int m)
{
    int N = n + m;
    int gap = (N / 2) + (N % 2);
    while (gap > 0)
    {
        for (int i = 0; i < N - gap; i++)
        {
            int n1 = i;
            int n2 = i + gap;

            if (n1 >= n)
            {
                n1 -= n;
                n2 -= n;
                if (B[n1] > B[n2])
                    swap(B[n1], B[n2]);
            }
            else if (n2 < n)
            {
                if (A[n1] > A[n2])
                    swap(A[n1], A[n2]);
            }
            else
            {
                n2 -= n;
                if (A[n1] > B[n2])
                    swap(A[n1], B[n2]);
            }
        }
        if (gap == 1)
            gap = 0;
        gap = (gap / 2) + (gap % 2);
        cout << gap << "\n";
    }
}

int main()
{

    int A[] = {7, 9, 9, 10, 11, 11, 13, 14, 17, 19}, B[] = {1, 1, 4, 5, 8, 11, 13, 16, 19, 19}, n = 10, m = 10;
    merge(A, B, n, m);
    printArr(A, n);
    printArr(B, m);
    return 0;
}