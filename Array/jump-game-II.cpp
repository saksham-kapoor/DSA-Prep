#include <iostream>
#include <vector>
using namespace std;

// to do: add function to print paths of minimum jump

int minJumps(vector<int> A)
{
    int n = A.size();
    vector<int> dp(n);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        int steps = A[i];
        int min = INT_MAX;

        for (int j = 1; j <= steps && i + j < n; j++)
            if (dp[i + j] != -1 && dp[i + j] < min)
                min = dp[i + j];

        if (min == INT_MAX)
            dp[i] = -1;
        else
            dp[i] = min + 1;
    }

    return dp[0];
}

int main()
{
    vector<int> A = {3, 3, 0, 2, 1, 2, 4, 2, 0, 0};
    int jumps = minJumps(A);
    cout << "Min Jumps: " << jumps;
    return 0;
}