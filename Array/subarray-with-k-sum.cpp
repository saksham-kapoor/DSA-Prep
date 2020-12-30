#include <unordered_set>
using namespace std;

// O(n) solution
bool subArrayExists(int arr[], int n)
{
    unordered_set<int> sums;
    int k = 6, sum = 0;
    sums.insert(sum);
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sums.find(sum - k) == sums.end())
            sums.insert(sum);
        else
            return true;
    }
    return false;
}