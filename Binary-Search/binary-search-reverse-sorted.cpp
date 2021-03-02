#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> A, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target == A[mid])
            return mid;
        else if (target < A[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> A = {11, 9, 8, 5, 4, 3, 1};
    cout << binary_search(A, 0, A.size() - 1, 5)
         << "\n";
    return 0;
}