#include <iostream>
#include <vector>
using namespace std;

void moveNegative(vector<int> &A)
{
    int l = 0, m = 0, h = A.size() - 1;
    while (m < A.size() && m >= l && m <= h)
    {
        if (A[m] < 0)
        {
            if (m == l)
                m++;
            else
            {
                if (A[l] >= 0)
                    swap(A[m], A[l]);
                l++;
            }
        }
        else if (A[m] > 0)
        {
            if (m == h)
                m++;
            else
            {
                if (A[h] <= 0)
                    swap(A[m], A[h]);
                h--;
            }
        }
        else
            m++;
    }
}

void printArr(vector<int> A)
{
    for (auto i : A)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> A = {-12, 11, 0, 0, 0, 0, 0, 5, -3, -6};
    moveNegative(A);
    printArr(A);
    return 0;
}