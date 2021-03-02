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
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int recursive_binary_search(vector<int> A, int start, int end, int target)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (target == A[mid])
        return mid;
    else if (target < A[mid])
        return recursive_binary_search(A, start, mid - 1, target);
    else
        return recursive_binary_search(A, mid + 1, end, target);
}

int main()
{
    vector<int> A = {1, 3, 4, 5, 8, 9, 11};
    cout << binary_search(A, 0, A.size() - 1, 11) << "\n";
    cout << recursive_binary_search(A, 0, A.size() - 1, 55);
    return 0;
}