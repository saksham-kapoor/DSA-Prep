#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Most optimal solution - O(N) space and time.
int countPairs(vector<int> A, int k)
{
    unordered_map<int, int> m;
    int count = 0;

    // O(n) storing as insertion in unordered_map takes O(1) time
    for (int i : A)
        m[i]++;

    for (int i : A)
    {
        int x = k - i;

        // we have to find x in the map
        count += m[x];

        // for pairs like (3,3) where k=6, it should not be counted 2 times.
        if (x == i)
            count--;
    }

    // here we have calculated every pair 2 times, therefore we will divide the final answer by 2.
    return count / 2;
}

int main()
{
    vector<int> A = {1, 5, 7, 1};
    int k = 6, ans;
    ans = countPairs(A, k);
    cout << "Number of pairs with given sum(" << k << "): " << ans;
    return 0;
}