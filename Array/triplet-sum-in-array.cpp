#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper for checkTripletsOptimal function - Using two pointer method - O(n) time
int twoSum(vector<int> A, int l, int h, int k)
{
    while (l < h)
    {
        int sum = A[l] + A[h];
        if (sum == k)
            return 1;
        else if (sum < k)
            l++;
        else
            h--;
    }
    return 0;
}

// Optimal Solution - O(n^2) + O(nlogn) time
int checkTripletsOptimal(vector<int> A, int K)
{
    int n = A.size();
    sort(A.begin(), A.end());
    for (int i = 0; i <= n - 3; i++)
    {
        int newSum = K - A[i];
        if (twoSum(A, i + 1, n - 1, newSum) == 1)
            return 1;
    }
    return 0;
}

// Brute Force - O(n^3) time
int checkTripletsBrute(vector<int> A, int K)
{
    int i, j, k, n = A.size();
    for (i = 0; i < n - 2; i++)
        for (j = i + 1; j < n - 1; j++)
            for (k = j + 1; k < n; k++)
                if (A[i] + A[j] + A[k] == K)
                    return 1;

    return 0;
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int n, k;
        cin >> n >> k;
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        cout << checkTripletsOptimal(A, k) << "\n";
        // cout << checkTripletsBrute(A, k) << "\n";
        T--;
    }
}