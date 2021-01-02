#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Best solution - O(N) time, O(1) space
int waterTrapped_Best(vector<int> A)
{
    // Two pointer approach
    int water = 0, n = A.size(), l = 0, h = n - 1, Lmax = -1, Rmax = -1;
    while (l < h)
        if (A[l] <= A[h])
        {
            if (A[l] > Lmax)
                Lmax = A[l];
            water += Lmax - A[l];
            l++;
        }
        else
        {
            if (A[h] > Rmax)
                Rmax = A[h];
            water += Rmax - A[h];
            h--;
        }
    return water;
}

// Better solution - O(N) time | O(N) space
int waterTrapped_Better(vector<int> A)
{
    // This method uses prefix, suffix arrays
    int Lmax = -1, Rmax = -1, n = A.size(), water = 0;

    // Create prefix & suffix array
    vector<int> prefix(n), suffix(n);

    // prefix array stores left max for element i
    // suffix array stores right max for element i
    for (int i = 0; i < n; i++)
    {
        if (A[i] > Lmax)
            Lmax = A[i];
        if (A[n - i - 1] > Rmax)
            Rmax = A[n - i - 1];
        prefix[i] = Lmax;
        suffix[n - i - 1] = Rmax;
    }

    // traverse main array
    for (int i = 0; i < n; i++)
    {
        int leftMax = prefix[i];
        int rightMax = suffix[i];
        water += min(leftMax, rightMax) - A[i];
    }

    return water;
}

// Helper Function - Returns max from given array
int getMax(vector<int> A, int l, int h)
{
    int max = A[l];
    for (int i = l + 1; i <= h; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}

// Brute Force Method - O(N2) time | O(1) space
int waterTrapped_Brute(vector<int> A)
{
    int n = A.size(), water = 0, leftMax, rightMax;
    for (int i = 0; i < n; i++)
    {
        leftMax = getMax(A, 0, i);
        rightMax = getMax(A, i, n - 1);
        water += min(leftMax, rightMax) - A[i];
    }
    return water;
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        cout << waterTrapped_Best(A) << "\n";
        // cout << waterTrapped_Better(A) << "\n";
        // cout << waterTrapped_Brute(A) << "\n";
        T--;
    }
    return 0;
}