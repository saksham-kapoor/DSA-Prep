#include <iostream>
#include <vector>
using namespace std;

struct Pair
{
    int min;
    int max;
} minmax;

void itMinMax(vector<int> A)
{
    int size = A.size();
    if (size == 1)
    {
        minmax.min = minmax.max = A[0];
        return;
    }

    if (A[0] > A[1])
    {
        minmax.max = A[0];
        minmax.min = A[1];
    }
    else
    {

        minmax.max = A[1];
        minmax.min = A[0];
    }

    if (size == 2)
        return;

    for (int i = 2; i < size; i++)
    {
        if (A[i] > minmax.max)
        {
            minmax.max = A[i];
        }
        else if (A[i] < minmax.min)
        {
            minmax.min = A[i];
        }
    }
}

Pair tournamentMinMax(vector<int> A, int low, int high)
{
    Pair mmt, mml, mmr;
    if (low == high)
    {
        mmt.max = mmt.min = A[low];
        return mmt;
    }
    if (low + 1 == high)
    {
        if (A[low] > A[high])
        {
            mmt.max = A[low];
            mmt.min = A[high];
        }
        else
        {
            mmt.max = A[high];
            mmt.min = A[low];
        }
        return mmt;
    }
    int mid = (low + high) / 2;
    mml = tournamentMinMax(A, low, mid);
    mmr = tournamentMinMax(A, mid + 1, high);
    (mml.max > mmr.max) ? mmt.max = mml.max : mmt.max = mmr.max;
    (mml.min < mmr.min) ? mmt.min = mml.min : mmt.min = mmr.min;
    return mmt;
}

void compareInPairs(vector<int> A)
{
    int size = A.size(), i;
    if (size % 2 != 0)
    {
        minmax.min = minmax.max = A[0];
        i = 1;
    }
    else
    {
        if (A[0] > A[1])
        {
            minmax.max = A[0];
            minmax.min = A[1];
        }
        else
        {
            minmax.max = A[1];
            minmax.min = A[0];
        }
        i = 2;
    }

    for (; i < size; i += 2)
    {
        if (A[i] > A[i + 1])
        {
            if (A[i] > minmax.max)
                minmax.max = A[i];
            if (A[i + 1] < minmax.min)
                minmax.min = A[i + 1];
        }
        else
        {
            if (A[i + 1] > minmax.max)
                minmax.max = A[i + 1];
            if (A[i] < minmax.min)
                minmax.min = A[i];
        }
    }
}

int main()
{
    vector<int> A = {2, 5, 8, 3, 4, 9, 7, 5, 9, 7, 4, 2, 6, 1, 5, 1, 5, 4};

    // simple iterative method
    // itMinMax(A);

    // tournament method (divide and conquer)
    // minmax = tournamentMinMax(A, 0, A.size() - 1);

    // compare in pairs method
    compareInPairs(A);

    // printing result
    cout << "MIN: " << minmax.min << " MAX: " << minmax.max;
    return 0;
}