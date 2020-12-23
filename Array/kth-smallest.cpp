#include <iostream>
#include <vector>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(vector<int> &A, int l, int h)
{
    int pivot = l;
    l++;
    do
    {
        while (A[l] < A[pivot])
            l++;
        while (A[h] > A[pivot])
            h--;
        if (l < h)
        {
            swap(&A[l], &A[h]);
        }
    } while (l < h);
    swap(&A[h], &A[pivot]);
    return h;
}

int kth_quickselect(vector<int> A, int l, int h, int k)
{
    int index = partition(A, l, h);
    if (index == k - 1)
    {
        return A[k - 1];
    }
    else
    {
        if (k - 1 > index)
            l = index + 1;
        else
            h = index - 1;
    }
    return kth_quickselect(A, l, h, k);
}

void quicksort(vector<int> &A, int l, int h)
{
    int index;
    if (l < h)
    {
        index = partition(A, l, h);
        quicksort(A, l, index - 1);
        quicksort(A, index + 1, h);
    }
}

int bruteforce_quicksort(vector<int> A, int k)
{
    int size = A.size();
    quicksort(A, 0, size - 1);
    return A[k - 1];
}

int delete_from_minheap(vector<int> &A)
{
    int x = A[0];
    A[0] = A[A.size() - 1];
    A.pop_back();
    int i = 0;
    int j = 2 * i + 1;
    while (j < A.size())
    {
        if (A[j + 1] < A[j])
            j++;
        if (A[j] < A[i])
        {
            swap(&A[j], &A[i]);
            i = j;
            j = 2 * i + 1;
        }
        else
            break;
    }
    return x;
}

int minheap(vector<int> A, int k)
{
    int size = A.size();
    // heapify
    int last_parent_node = ((size - 1) - 1) / 2;
    for (int i = last_parent_node; i >= 0; i--)
    {
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < size && A[i] > A[l])
            swap(&A[i], &A[l]);
        if (r < size && A[i] > A[r])
            swap(&A[i], &A[r]);
    }
    // delete k elements from heap
    for (int i = 0; i < k - 1; i++)
        delete_from_minheap(A);

    return delete_from_minheap(A);
}

int main()
{
    vector<int> A = {7, 10, 4, 3, 20, 15};
    int ans, k = 3;

    // simple solution
    // ans = bruteforce_quicksort(A, k);

    // heap solution
    ans = minheap(A, k);
    // quick select solution
    // ans = kth_quickselect(A, 0, A.size() - 1, k);

    cout << k << "th smallest element: " << ans;
    return 0;
}