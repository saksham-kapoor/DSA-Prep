#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &A, int x)
{
    if (A.size() == 0 || A.back() <= x)
    {
        A.push_back(x);
        return;
    }
    int temp = A.back();
    A.pop_back();
    insert(A, x);
    A.push_back(temp);
}

void sort(vector<int> &A)
{
    if (A.size() == 1)
        return;
    int temp = A.back();
    A.pop_back();
    sort(A);
    insert(A, temp);
}

void print(vector<int> A)
{
    for (int i : A)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    vector<int> A = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    sort(A);
    print(A);
    return 0;
}