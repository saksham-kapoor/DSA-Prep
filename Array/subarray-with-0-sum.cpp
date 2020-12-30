#include <unordered_set>
using namespace std;

// O(n) solution
bool subArrayExists(int arr[], int n)
{
    unordered_set<int> sums;
    int sum = 0;
    sums.insert(sum);
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sums.find(sum) == sums.end())
            sums.insert(sum);
        else
            return true;
    }
    return false;
}